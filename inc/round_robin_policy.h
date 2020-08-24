#ifndef ROUND_ROBIN_POLICY_H
#define ROUND_ROBIN_POLICY_H

#include<load_balancer_config.h>
#include<http_client.h>

void round_robin_policy_init();

transaction_client* round_robin_policy_get(HttpRequest* hrq);

void round_robin_policy_destroy();

#endif