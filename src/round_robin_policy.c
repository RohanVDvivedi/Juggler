#include<round_robin_policy.h>

extern transaction_client* http_clients[SERVER_COUNT];

transaction_client* round_robin_get(HttpRequest* hrq)
{
	return NULL;
}