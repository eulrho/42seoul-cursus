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

# RUN mkdir -p /var/www/html/wordpress/wp-content/uploads/2024/02
# COPY ./conf/uploads/* /var/www/html/wordpress/wp-content/uploads/2024/02
# RUN chmod -R 755 /var/www/html/wordpress/wp-content/uploads/
# RUN chomod 644 /var/www/html/wordpress/wp-content/uploads/2024/02/*
# RUN chown -R www-data:www-data /var/www/html/wordpress/wp-content/uploads/

CMD ["php-fpm", "-F"]