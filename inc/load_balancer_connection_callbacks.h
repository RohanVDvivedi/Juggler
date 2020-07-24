#ifndef LOAD_BALANCER_CONNECTION_CALLBACKS_H
#define LOAD_BALANCER_CONNECTION_CALLBACKS_H

#include<http_client_access.h>

void connection_started(int conn_fd, const void* params);
void connection_finished(int conn_fd, const void* params);

#endif