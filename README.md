# Juggler
A light weight L7 Load balancer application built on top of framework serc.

Supports (only) Round-robin load balancing policy.

 * It does not support connection persistence, i.e. session stickyness.
 * I urge you to not use juggler for long lived connections like those of chat servers or http streaming. No web sockets stuff what so ever.
 * Juggler maintains only a finite number of tcp connections to the backend server and hence, new client connection does not add another tcp connection to the backend server. Instead Juggler waits and receives the complete http request, parses it, and forwards the request to respective server, and then when the server finishes the response, we send back the response, the next request now will got to a completely different server (the one which is next in round robin list).
 * Essentially the backend http servers always think that Juggler is the client, making each request with a KeepAlive : true header, no other headers are modified by the Juggler.
 * Juggler does supports https and http connection from client (say browser) to Juggler, but you must use only a http server for backend (running on different hosts or port). This way Juggler is a load balancer which you would want to keep closer to servers on the network, since your servers are free from the responsibility of performing a SSL handshake.

## Policy
 #### Round-robin policy
  * Round robin algorithm to select the server for every new connection.
  * All the requests from the same client DO NOT reach the same backend server.

##Steps you need to do for setup are:

### For setup before first run :
 * you must install [serc](https://github.com/RohanVDvivedi/serc.git) and its dependencies.

### For setting up the https Juggler :
 * checkout main source file at src/main.c
 * use appropriate https server run line
 * add ssl certificates (you may use `make ssl_cert` for building self signed certificates)

### For managing Juggler :

 * #### to update routing 
   * `make routes`
   * this will create a source file "distributer.c" in your src folder, you need to compile it with your application and serc
   * the above point is already taken care of by `make all`, read makefile and read serc source for more information.

 * #### to built self signed ssl certificates and private/public keys (if you want to use https)
   * `make ssl_cert`

 * #### to clean all binaries (this will also delete the distributer.c source)
   * `make clean`

 * #### to build your application
   * `make all`

 * #### to change load balancing configurtions of Juggler
   * checkout configuration file ./juggler_config/load_balancer_config.h

 * #### to run your application
   * `sudo ./bin/app.out`

### To run test servers
 * `serc --port=6901 --root=./test_server_root_1`
 * `serc --port=6902 --root=./test_server_root_2`
 * `serc --port=6903 --root=./test_server_root_3`
