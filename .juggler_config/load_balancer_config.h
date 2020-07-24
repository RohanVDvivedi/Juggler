#ifndef LOAD_BALANCER_CONFIG_H
#define LOAD_BALANCER_CONFIG_H

#define LOAD_BALANCING_POLICY ROUND_ROBIN /*CONSISTENT_HASHING*/

#define SERVER_COUNT		 3
#define SERVER_IPS {"localhost", "localhost", "localhost"}
#define SERVER_PORTS {"6901", "6902", "6903"}

#define CONNECTIONS_PER_SERVER 5

#endif