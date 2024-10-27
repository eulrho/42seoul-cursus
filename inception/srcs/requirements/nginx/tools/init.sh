#!/bin/bash

openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:4096 -keyout $CERTS_KEY -out $CERTS_CRT -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Inception/CN=${DOMAIN_NAME}"

chmod 600 $CERTS_CRT $CERTS_KEY

sed -i "s|DOMAIN_NAME|$DOMAIN_NAME|g" /etc/nginx/conf.d/nginx.conf
sed -i "s|KEY_PATH|$CERTS_KEY|g" /etc/nginx/conf.d/nginx.conf
sed -i "s|CRT_PATH|$CERTS_CRT|g" /etc/nginx/conf.d/nginx.conf

exec "$@"