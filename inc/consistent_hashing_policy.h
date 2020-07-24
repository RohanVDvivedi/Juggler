#ifndef CONSISTENT_HASHING_POLICY_H
#define CONSISTENT_HASHING_POLICY_H

#include<load_balancer_config.h>
#include<http_client.h>

transaction_client* consistent_hashing_get(HttpRequest* hrq);

#endif