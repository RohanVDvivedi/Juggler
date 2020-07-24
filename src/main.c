#include<stdio.h>
#include<stdlib.h>

#include<http_server.h>
#include<http_client.h>

#include<load_balancer_config.h>

#include<load_balancer_connection_callbacks.h>

char* server_ips[SERVER_COUNT] = SERVER_IPS;
char* server_ports[SERVER_COUNT] = SERVER_PORTS;
transaction_client* http_clients[SERVER_COUNT] = {};

int main()
{
	for(int i = 0; i < SERVER_COUNT; i++)
		http_clients[i] = get_http_client(server_ips[i], server_ports[i], CONNECTIONS_PER_SERVER);

	http_server_run(80, NULL, 0);
	//http_server_run(443, NULL, 1);

	for(int i = 0; i < SERVER_COUNT; i++)
		shutdown_and_delete_http_client(http_clients[i]);
	
	return 0;
}