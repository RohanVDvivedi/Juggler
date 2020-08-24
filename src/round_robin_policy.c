#include<round_robin_policy.h>

extern transaction_client* http_clients[SERVER_COUNT];

unsigned int next_server_to_use = 0;
pthread_mutex_t next_server_to_use_lock;

void round_robin_policy_init()
{
	next_server_to_use = 0;
	pthread_mutex_init(&next_server_to_use_lock, NULL);
}

transaction_client* round_robin_policy_get(HttpRequest* hrq)
{
	pthread_mutex_lock(&next_server_to_use_lock);
		unsigned int server_to_use = next_server_to_use;
		next_server_to_use = (next_server_to_use + 1) % SERVER_COUNT;
	pthread_mutex_unlock(&next_server_to_use_lock);

	transaction_client* server = http_clients[server_to_use];

	return server;
}

void round_robin_policy_destroy()
{
	pthread_mutex_destroy(&next_server_to_use_lock);
}