FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y wget php7.4-fpm php7.4-mysql mariadb-client
RUN rm -rf /var/lib/apt/lists/*

RUN mv /etc/php/7.4/fpm/pool.d/www.conf /etc/php/7.4/fpm/pool.d/www.conf.default
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d
RUN ln -s $(find /usr/sbin -name 'php-fpm*') /usr/bin/php-fpm

EXPOSE 9000

RUN mkdir -p /run/php
RUN chmod 755 /run/php

COPY ./tools/init.sh /usr/local/bin
RUN chmod +x /usr/local/bin/init.sh
ENTRYPOINT ["/usr/local/bin/init.sh"]

CMD ["php-fpm", "-F"]