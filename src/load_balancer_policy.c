#include<load_balancing_policy.h>

#include<round_robin_policy.h>
#include<consistent_hashing_policy.h>

transaction_client* get_http_server_for_forwarding(HttpRequest* hrq, load_balancing_policy policy)
{
	transaction_client* http_server_res = get_persistent_http_client();

	if(http_server_res == NULL)
	{
		switch(policy)
		{
			case ROUND_ROBIN :
			{
				http_server_res = round_robin_get();
				break;
			}
			case CONSISTENT_HASHING :
			{
				http_server_res = consistent_hashing_get();
				break;
			}
		}

		set_for_persistence_http_client(http_server_res);
	}

	return http_server_res;
}