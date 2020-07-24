#include<stdio.h>
#include<stdlib.h>

#include<http_server.h>
#include<http_client.h>

#include<load_balancer_config.h>

#include<load_balancer_connection_callbacks.h>

int main()
{
	void* global_http_client_finder = NULL;
	for(int i = 0; i < SERVER_COUNT; i++)
	{
		transaction_client* http_client = get_http_client("url_string", "port_string", CONNECTIONS_PER_SERVER);
	}

	http_server_run(80, NULL, 0, connection_started, connection_finished, global_http_client_finder);
	//http_server_run(443, NULL, 1, connection_started, connection_finished, global_http_client_finder);

	delete_http_client_access_key();
	
	return 0;
}