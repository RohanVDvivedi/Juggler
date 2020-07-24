#include<http_client_access.h>

// the once lets you create the "pthread key for accessing http_client" only once 

transaction_client* get_http_client();

void* set_http_client(transaction_client* http_client);

void delete_http_client_access_key();