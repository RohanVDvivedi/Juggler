#include<distributer.h>

// forward declrations of all your controller functions

int load_balancing_controller(HttpRequest* hrq,HttpResponse* hrp);


void distribute(HttpRequest* hrq,HttpResponse* hrp,file_content_cache* fcc_p)
{
	char* path_str = hrq->path.cstring;
	unsigned long long int path_len = hrq->path.bytes_occupied;
	unsigned long long int PATH = getHashValue(path_str);
	HttpMethod METHOD = hrq->method;

	int routing_resolved = 0;
	int error = 0;

	uncompressHttpRequestBody(hrq);

	switch(METHOD)
	{
		case CONNECT :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = CONNECT
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case PATCH :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = PATCH
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case PUT :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = PUT
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case OPTIONS :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = OPTIONS
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case HEAD :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = HEAD
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case DELETE :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = DELETE
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case GET :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = GET
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case POST :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = POST
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		case TRACE :
		{
			switch(PATH)
			{
				default : 
				{
					char* wild_card_offset = NULL;
					// case for path = /* and supports method = TRACE
					if( (1 <= path_len) && (NULL != (wild_card_offset = strstr(path_str, "/"))) )
					{
						routing_resolved = 1;
						hrp->status = 200;
						error = load_balancing_controller(hrq, hrp);
					}
					else
					{
						hrp->status = 404;
					}
					break;
				}
			}
			break;
		}
		default :
		{
			hrp->status = 404;
		}
	}

	if(routing_resolved==0)
	{
		// check if we can serve the request with some file, on the server's root
		error = file_request_controller(hrq,hrp,fcc_p,&routing_resolved);
		if(routing_resolved==0)
		{
			hrp->status = 404;
		}
	}

	// response for a HEAD request must not contain body
	if(METHOD == HEAD)
	{
		make_dstring_empty(&(hrp->body));
	}

	compressHttpResponseBody(hrp, DEFAULT_COMPRESSION);

	setServerDefaultHeadersInResponse(hrp);
}