#include<load_balancing_policy.h>

extern transaction_client* http_clients[SERVER_COUNT];

transaction_client* get_http_client_for_forwarding(HttpRequest* hrq, load_balancing_policy policy)
{
	return NULL;
}