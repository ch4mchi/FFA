#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>

//compile : gcc -o (name) (src) -L /usr/local/lib/ -l sqlite3

struct FFA_AP_info{
	char ap_essid[256];
	char ap_bssid[18];
	int  ap_channel;
};

struct FFA_client_info{
	char conn_ap_bssid[18];
	char client_bssid[18];
};

sqlite3 *db;
sqlite3_stmt *stmt;
char *ErrMsg;
int rc;

int insert_delete_callback(void *, int , char **, char **);

int connect_db(char *);
int close_db();
int execute_query(char *, int (*)(void *, int, char **, char**), void *);

int insert_ap(struct FFA_AP_info);
int get_select_ap_count();
void select_ap(struct FFA_AP_info *);
int delete_ap();

int insert_client(struct FFA_client_info);
int get_select_client_count(struct FFA_AP_info);
void select_client(struct FFA_client_info[], struct FFA_AP_info);
int delete_client();
