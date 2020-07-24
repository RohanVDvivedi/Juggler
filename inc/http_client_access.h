#ifndef HTTP_CLIENT_ACCESS_H
#define HTTP_CLIENT_ACCESS_H

/*
	This header lets you insert, remove or get the transaction client
	for only your specific thread/connection
*/

#include<http_client.h>

transaction_client* get_persistent_http_client();

void set_for_persistence_http_client(transaction_client* http_client);

void delete_http_client_access_key();

#endif