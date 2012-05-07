compile : gcc -o (output) (src) FFA_sqlite3.c -L /usr/local/lib -l sqlite3

--basic

#include "FFA_sqlite3.h"

write connect_db(db); at the front of source
	ex) connect_db("FFA.db");

--functions

insert_ap : insert new AP to database
	ex)
		struct AP_info newAP;

		strcpy(newAP.ap_essid, "KoreaUniv AP");
		strcpy(newAP.ap_bssid, "123abc");
		newAP.channel = 10;
		
		insert_ap(newAP);

get_select_ap_count : get number of rows in result of "select * from AP"
		      it is necessary for allocate memory to (struct AP_info *)
	ex)
		struct AP_info *AP_arr;
		int ap_n;
		
		ap_n = get_select_ap_count();
		
		AP_arr = (struct AP_info *)malloc(ap_n * sizeof(struct AP_info));

select_ap : get all APs from database
	ex)
		//use above AP_arr
		select_ap(AP_arr);

delete_ap : delete all APs from database when program is exit
	ex)
		delete_ap();

insert_client : insert new client to database
	ex)
		struct client_info newClient;
		
		strcpy(newClient.conn_ap_bssid, "456def");
		strcpy(newClient.client_bssid, "789123");
		
		insert_client(newClient);

get_select_client_count : get number of rows in result of select, that clients are connect to specific AP
	ex)
		//use above newAP
		struct client_info *clientArr;
		int cl_n;
		
		cl_n = get_select_client_count(newAP);

		clientArr = (struct client_info *)malloc(cl_n * sizeof(struct client_info));

select_client : select all clients which are connect to specific AP
	ex)
		//use above clientArr, newAP
		
		select_client(clientArr, newAP);
		//get all clients connect to newAP

delete_client : delete all clients from database
	ex)
		delete_client();
