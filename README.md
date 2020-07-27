# Juggler
an L7 Load balancer using the server application built on top of framework serc.

Supports Round-robin and Consistent-hashing based load balancing.

Note: It supports connection persistence for medium-lived HTTP connections, generally used for web browsing.
Note: I urge you to not use juggler for long lived connections like those of chat servers or http streaming.

Steps you need to do are :

### For setup before first run :
 * you must install [serc](https://github.com/RohanVDvivedi/serc.git)

### For setting up the https server :
 * checkout main source file at src/main.c
 * use appropriate https server run line
 * add ssl certificates (you may use `make ssl_cert` for building self signed certificates)

### For managing your application :

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

 * #### to run your application
   * `sudo ./bin/app.out`
