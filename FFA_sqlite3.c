#include "FFA_sqlite3.h"

int connect_db(char *db_name)
{
	int chk;

	rc = sqlite3_open(db_name, &db);
	if(rc)
	{
		fprintf(stderr, "Can't open database : %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		
		return -1;
	}
	
	chk = execute_query("create table if not exists AP (ap_essid char(256), ap_bssid char(17) primary key, ap_channel int)", 0, 0);
	if(chk == -1)
	{
		puts("create table \"AP\" error");

		return -1;
	}

	chk = execute_query("create table if not exists client (conn_ap_bssid char(17), client_bssid char(17) primary key)", 0, 0);
	if(chk == -1)
	{
		puts("create table \"client\" error");

		return -1;
	}

	return 0;
}

int close_db()
{
	rc = sqlite3_close(db);
	if(rc)
	{
		fprintf(stderr, "Can't close database : %s\n", sqlite3_errmsg(db));
		
		return -1;
	}

	return 0;
}

int execute_query(char *query, int (*callback)(void *, int, char **, char **), void *result)
{
	rc = sqlite3_exec(db, query, callback, result, &ErrMsg);
	
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL Error : %s\n", ErrMsg);
		sqlite3_free(ErrMsg);

		return -1;
	}

	return 0;
}
	
int insert_ap(struct FFA_AP_info AP)
{
	int chk;
	char query[309];

	sprintf(query, "insert into AP values(\"%s\", \"%s\", %d)", AP.ap_essid, AP.ap_bssid, AP.ap_channel);

	chk = execute_query(query, 0 ,0);
	if(chk == -1)
	{
		puts("insert ap error");
		return -1;
	}

	return 0;
}

int get_select_ap_count()
{
	int rows, cols;
	int ret;
	char **res;
	char *query = sqlite3_mprintf("select * from AP");
	
	ret = sqlite3_get_table(db, query, &res, &rows, &cols, &ErrMsg);
	sqlite3_free(query);
	
	if(ret != SQLITE_OK){
		puts(ErrMsg);
		return -1;
	}
	
	sqlite3_free_table(res);

	return rows;
}

void select_ap(struct FFA_AP_info *APs)
{
	int retval;
	int cols, col;
	int index = 0;
	const char * val;

	retval = sqlite3_prepare_v2(db, "select * from AP", -1, &stmt, 0);
	if(retval)
	{
		printf("error\n");
		exit(-1);
	} 

	cols = sqlite3_column_count(stmt);

	while(1)
	{
		retval = sqlite3_step(stmt);

		if(retval == SQLITE_ROW)
		{
			for(col = 0; col < cols ; col++)
			{
				val = (const char *)sqlite3_column_text(stmt, col);
				
				if(col == 0)
					sprintf(APs[index].ap_essid, "%s", val);
				else if(col == 1)
					sprintf(APs[index].ap_bssid, "%s", val);
				else if(col == 2)
					APs[index].ap_channel = atoi(val);

			}

			index++;
		}
		else if(retval == SQLITE_DONE)
			break;
	}
}

int delete_ap()
{
	int chk = execute_query("delete from AP", 0, 0);

	if(chk == -1)
	{
		puts("delete_ap error");
		return -1;
	}

	return 0;
}

int insert_client(struct FFA_client_info client)
{
	char query[68];
	int chk;

	sprintf(query, "insert into client values(\"%s\", \"%s\")", client.conn_ap_bssid, client.client_bssid);	

	chk = execute_query(query, 0, 0);

	if(chk == -1)
	{
		puts("insert_client error");
		return -1;
	}

	return 0;
}

int get_select_client_count(struct FFA_AP_info conn_AP)
{
	int rows, cols;
	int ret;
	char **res;
	char *zQuery;
	char query[100];

	sprintf(query, "select distinct client.* from client JOIN AP where client.conn_ap_bssid = \"%s\"", conn_AP.ap_bssid);

	zQuery = sqlite3_mprintf(query);
	ret = sqlite3_get_table(db, zQuery, &res, &rows, &cols, &ErrMsg);
	sqlite3_free(zQuery);
	
	if(ret != SQLITE_OK){
		puts(ErrMsg);
		return -1;
	}
	
	sqlite3_free_table(res);

	return rows;
}

void select_client(struct FFA_client_info clnts[], struct FFA_AP_info conn_AP)
{
	int retval;
	int cols, col;
	int index = 0;
	const char *val;
	char query[100];

	sprintf(query, "select distinct client.* from client JOIN AP where client.conn_ap_bssid = \"%s\"", conn_AP.ap_bssid);

	retval = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
	if(retval)
	{
		printf("error\n");
		exit(-1);
	}

	cols = sqlite3_column_count(stmt);

	while(1)
	{
		retval = sqlite3_step(stmt);
		
		if(retval == SQLITE_ROW)
		{
			for(col = 0 ; col < cols ; col++)
			{
				val = (const char *)sqlite3_column_text(stmt, col);

				if(col == 0)
					sprintf(clnts[index].conn_ap_bssid, "%s", val);
				else if(col == 1)
					sprintf(clnts[index].client_bssid, "%s", val);
			}

			index++;
		}
		else if(retval == SQLITE_DONE)
			break;
	}
}

int delete_client()
{
	int chk = execute_query("delete from client", 0, 0);

	if(chk == -1)
	{
		puts("delete_client error");
		return -1;
	}

	return 0;
}
