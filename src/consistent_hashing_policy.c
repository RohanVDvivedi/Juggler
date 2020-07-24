#include<consistent_hashing_policy.h>

extern transaction_client* http_clients[SERVER_COUNT];

transaction_client* consistent_hashing_get(HttpRequest* hrq)
{
	return NULL;
}