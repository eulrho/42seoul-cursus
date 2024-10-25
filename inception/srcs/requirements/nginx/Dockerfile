FROM debian:bullseye

RUN apt-get update
RUN apt-get install -y nginx openssl
RUN rm -rf /var/lib/apt/lists/*

RUN sed -i 's/ssl_protocols.*/ssl_protocols TLSv1.3;/' /etc/nginx/nginx.conf

COPY ./conf/nginx.conf /etc/nginx/conf.d/
RUN chmod +x /etc/nginx/conf.d/nginx.conf

RUN mkdir -p /run/nginx
RUN chmod 755 /run/nginx
RUN mkdir /etc/nginx/ssl

COPY ./tools/init.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init.sh
ENTRYPOINT ["/usr/local/bin/init.sh"]

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]