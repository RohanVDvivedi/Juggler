#ifndef CONFIG_H
#define CONFIG_H

#define DEFAULT_SERVER_RESPONSE_COMPRESSION GZIP
// possible values are DEFLATE, GZIP, BROTLI

// this defines what SSL encryption and SSL certificates folder would be used for serving content
#define SSL_PUB_CERTIFICATE			"./.serc_config/server_pub_cert.crt"
#define SSL_PRIVATE_KEY				"./.serc_config/server_priv_key.key"
#define SSL_SERVER_METHOD			TLSv1_2_server_method 

// for more options to SSL_SERVER_METHOD, use openSSL documentation

#endif