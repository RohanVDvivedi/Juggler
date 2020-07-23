#include<stdio.h>
#include<stdlib.h>

#include<http_server.h>

int main()
{
	http_server_run(80, NULL, 0, NULL, NULL);
	//http_server_run(443, NULL, 1, NULL, NULL);
	return 0;
}