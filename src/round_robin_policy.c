#include<round_robin_policy.h>

extern transaction_client* http_clients[SERVER_COUNT];

transaction_client* round_robin_get(HttpRequest* hrq)
{
	static unsigned int next_server_to_use = 0;

	transaction_client* server = http_clients[next_server_to_use];

	next_server_to_use = (next_server_to_use+1) % SERVER_COUNT;

	return server;
}