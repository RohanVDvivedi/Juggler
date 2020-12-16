# Juggler
A light weight L7 Load balancer application built on top of framework serc.

Supports (only) Round-robin load balancing policy.

 * It does not support **connection persistence, i.e. session stickyness**.
 * I urge you to not use Juggler for long lived connections like those of chat servers or http streaming. No web sockets stuff what so ever.
 * Juggler maintains only a **finite number of tcp connections to the backend server** and hence, new client connection does not add another tcp connection to the backend server.
 * **Procedure:**
   * Instead Juggler waits and listens for new clients.
   * It also maintaines a finite number of connection to each backend server, over separate threads on a thread pool.
     * 1-1 relation between thread pool and server
     * 1-1 relation between thread and a tcp connection with the server
     * with n number of thread in a thread pool, each getting served by n distinct connections of that server.
     * for m number of servers (in round robin list), there are m number of thread pools.
     * for m number of servers, there are m * n number of total threads.
   * Each of this thread is a part of a thread pool, and is devised to pick request objects and service them over an exclusive active connection (which is only accessible by that thread).
   * When the client connection starts/connects, no new server side connection is made.
   * Instead Juggler will wait for the client request to finish, and it will parse it and put it on a queue to be serviced by the thread pool, which is responsible to be served by a specific server.
   * And later send the response back to the client. The new request from the client ends up with the next server/thread pool in the round robin list.
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
