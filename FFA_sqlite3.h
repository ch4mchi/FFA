#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>

//compile : gcc -o (name) (src) -L /usr/local/lib/ -l sqlite3

struct AP_info{
	char ap_essid[256];
	char ap_bssid[7];
	int  ap_channel;
};

struct client_info{
	char conn_ap_bssid[7];
	char client_bssid[7];
};

sqlite3 *db;
sqlite3_stmt *stmt;
char *ErrMsg;
int rc;

char *itoa(int);

int insert_delete_callback(void *, int , char **, char **);

int connect_db(char *);
int execute_query(char *, int (*)(void *, int, char **, char**), void *);

int insert_ap(struct AP_info);
int get_select_ap_count();
void select_ap(struct AP_info *);
int delete_ap();

int insert_client(struct client_info);
int get_select_client_count(struct AP_info);
void select_client(struct client_info[], struct AP_info);
int delete_client();
