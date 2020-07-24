#include<http_request.h>
#include<http_response.h>

#include<load_balancing_policy.h>
#include<load_balancer_config.h>

int load_balancing_controller(HttpRequest* hrq, HttpResponse* hrp)
{
	printRequest(hrq);

	transaction_client* http_server_to_use = get_http_server_for_forwarding(hrq, LOAD_BALANCING_POLICY);
	
	job* promise = send_request_async(http_server_to_use, hrq, "juggler.lb");

	HttpResponse* hrp_received = wait_or_get_response(promise, NULL);

	*hrp = *hrp_received;

	free(hrp_received);

	printResponse(hrp);

	return 0;
}