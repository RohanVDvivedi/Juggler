#ifndef LOAD_BALANCING_POLICY_H
#define LOAD_BALANCING_POLICY_H

typedef enum load_balancing_policy load_balancing_policy;
enum load_balancing_policy
{
	ROUND_ROBIN,
	CONSISTENT_HASHING
};

#endif