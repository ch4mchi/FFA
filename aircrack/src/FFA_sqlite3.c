#include "FFA_sqlite3.h"

char *itoa(int n)
{
	char *str_n;

	if(n >= 10)
	{
		str_n = (char*)malloc(2*sizeof(char));
		sprintf(str_n, "%d", n);
	}
	else
	{
		str_n = (char*)malloc(sizeof(char));
		sprintf(str_n, "%d", n);
	}
	
	return str_n;
}

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
	
	chk = execute_query("create table if not exists AP (ap_essid char(256), ap_bssid char(6) primary key, ap_channel int)", 0, 0);
	if(chk == -1)
	{
		puts("create table \"AP\" error");

		return -1;
	}

	chk = execute_query("create table if not exists client (conn_ap_bssid char(6), client_bssid char(6) primary key)", 0, 0);
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
	char query[299] = "insert into AP values(\"";
	
	int essid_len = strlen(AP.ap_essid);
	int channel_len = strlen(itoa(AP.ap_channel));
	int chk;
	
	strncat(query, AP.ap_essid, essid_len);
	strcat(query, "\", \"");

	strncat(query, AP.ap_bssid, 6);
	strcat(query, "\", ");
	
	strncat(query, itoa(AP.ap_channel), channel_len);
	strcat(query, ")");
	puts(query);
	chk = execute_query(query, 0, 0);
	puts("query 1");
	if(chk == -1) 
	{
		puts("insert_ap error");
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
					strncpy(APs[index].ap_essid, val, strlen(val)+1);
				else if(col == 1)
					strncpy(APs[index].ap_bssid, val, 7);
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
	char query[46] = "insert into client values(\"";

	int chk;

	strncat(query, client.conn_ap_bssid, 6);
	strcat(query, "\", \"");

	strncat(query, client.client_bssid, 6);
	strcat(query, "\")");

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
	char query[82] = "select distinct client.* from client JOIN AP where client.conn_ap_bssid = \"";
	
	strncat(query, conn_AP.ap_bssid, 6);
	strcat(query, "\"");
	
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
	char query[82] = "select distinct client.* from client JOIN AP where client.conn_ap_bssid = \"";

	strncat(query, conn_AP.ap_bssid, 6);
	strcat(query, "\"");

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
					strncpy(clnts[index].conn_ap_bssid, val, 7);
				else if(col == 1)
					strncpy(clnts[index].client_bssid, val, 7);
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
