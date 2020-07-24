#include<http_request.h>
#include<http_response.h>

#include<http_client.h>

#include<load_balancer_config.h>

#include<load_balancing_policy.h>

extern transaction_client* http_clients[SERVER_COUNT];

int load_balancing_controller(HttpRequest* hrq, HttpResponse* hrp)
{
	printRequest(hrq);
	append_to_dstring(&(hrp->body), "Hello World");
	return 0;
}