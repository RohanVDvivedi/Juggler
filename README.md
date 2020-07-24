# Juggler
an L7 Load balancer using the server application built on top of framework serc.

Supports Round-robin and Consistent-hashing based load balancing.

Note: It supports connection persistence for medium-lived HTTP connections, generally used for web browsing.
Note: I urge you to not use for long lived connections like those of chat servers or http streaming.

Steps you need to do are :

### For first run :

* mkdir .serc_framework
* cd .serc_framework
* git clone https://github.com/RohanVDvivedi/serc.git
* cd ..
* make routes clean all
* **set up necessary configurations in .juggler_config folder**

### For https server :

* checkout main source file at src/main.c
* use appropriate https server run line
* add ssl certificates (you may use `make ssl_cert` for building self signed certificates)

### For subsequent run :

* #### to update serc framework
  * `make update_serc`

* #### to update routing 
  * `make routes`

* #### to built self signed ssl certificates and private/public keys (if you want to use https)
  * `make ssl_cert`

* #### to clean all binaries (including serc binaries)
  * `make clean`

* #### to build application
  * `make all`
