#!/bin/bash

wget -O ./wordpress.tar.gz http://wordpress.org/latest.tar.gz
tar -xvf wordpress.tar.gz
mkdir -p /var/www/html/
mv wordpress/* /var/www/html/
rm -rf wordpress.tar.gz

chown -R www-data:www-data /var/www/html/

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -O /usr/local/bin/wp
chmod +x /usr/local/bin/wp

mv /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpress/wp-config.php
wp config set DB_NAME $MYSQL_DATABASE --allow-root --path=/var/www/html
wp config set DB_USER $MYSQL_USER --allow-root --path=/var/www/html
wp config set DB_PASSWORD $MYSQL_PASSWORD --allow-root --path=/var/www/html
wp config set DB_HOST mariadb --allow-root --path=/var/www/html

exec "$@"