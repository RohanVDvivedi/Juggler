#ifndef ROUND_ROBIN_POLICY_H
#define ROUND_ROBIN_POLICY_H

#include<load_balancer_config.h>
#include<http_client.h>

transaction_client* round_robin_get();

#endif