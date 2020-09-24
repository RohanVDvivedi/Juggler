#include<http_request.h>
#include<http_response.h>

#include<stdlib.h>

#include<round_robin_policy.h>
#include<load_balancer_config.h>

int load_balancing_controller(HttpRequest* hrq, HttpResponse* hrp)
{
	transaction_client* http_server_to_use = round_robin_policy_get(hrq);
	
	// add keep alive header to keep the connection alive
	insert_unique_in_dmap_cstr(&(hrq->headers), "Connection", "Keep-Alive");
	insert_unique_in_dmap_cstr(&(hrq->headers), "Keep-Alive", "always");

	promise* promise = send_request_async(http_server_to_use, hrq, "juggler.lb");
	HttpResponse* hrp_received = wait_or_get_response(promise);
	if(hrp_received != NULL)
	{
		deinitHttpResponse(hrp);
		*hrp = *hrp_received;
		free(hrp_received);
	}
	else
		hrp->status = 500;

	return 0;
}