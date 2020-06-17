#ifndef LOAD_BALANCER_CONFIG_H
#define LOAD_BALANCER_CONFIG_H

#define LOAD_BALANCING_POLICY ROUND_ROBIN /*CONSISTENT_HASHING*/

#define SERVER_ADDRESSES ["localhost:6901", "localhost:6902", "localhost:6903"]

#define CONNECTIONS_PER_SERVER 5

#endif