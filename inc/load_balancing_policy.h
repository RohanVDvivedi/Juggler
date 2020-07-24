#ifndef LOAD_BALANCING_POLICY_H
#define LOAD_BALANCING_POLICY_H

#include<load_balancer_config.h>

#include<http_client_access.h>

typedef enum load_balancing_policy load_balancing_policy;
enum load_balancing_policy
{
	ROUND_ROBIN,
	CONSISTENT_HASHING
};

transaction_client* get_http_server_for_forwarding(HttpRequest* hrq, load_balancing_policy policy);

#endif