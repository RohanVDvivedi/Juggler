#include<http_request.h>
#include<http_response.h>

#include<stdlib.h>

#include<round_robin_policy.h>
#include<load_balancer_config.h>

int load_balancing_controller(HttpRequest* hrq, HttpResponse* hrp)
{
	transaction_client* http_server_to_use = round_robin_policy_get(hrq);
	
	job* promise = send_request_async(http_server_to_use, hrq, "juggler.lb");
	HttpResponse* hrp_received = wait_or_get_response(promise, NULL);
	deinitHttpResponse(hrp);
	*hrp = *hrp_received;
	free(hrp_received);

	return 0;
}