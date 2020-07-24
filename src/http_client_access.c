#include<http_client_access.h>

// we use the server to store the calculated by load balancing
pthread_key_t http_server_for_connection_persistence;

// destructor for data pointer to by key
void destructor(void* a)
{

}

// the once lets you create the "pthread key for accessing http_client" only once 
pthread_once_t once_http_access_key_create = PTHREAD_ONCE_INIT;

void key_create_once()
{
	pthread_key_create(&http_server_for_connection_persistence, destructor);
}

transaction_client* get_persistent_http_client()
{
	pthread_once(&once_http_access_key_create, key_create_once);
	return pthread_getspecific(http_server_for_connection_persistence);
}

void set_for_persistence_http_client(transaction_client* http_client)
{
	pthread_once(&once_http_access_key_create, key_create_once);
	pthread_setspecific(http_server_for_connection_persistence, http_client);
}

void delete_http_client_access_key()
{
	pthread_once(&once_http_access_key_create, key_create_once);
	pthread_key_delete(http_server_for_connection_persistence);
}