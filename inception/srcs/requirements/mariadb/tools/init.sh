#!/bin/bash

service mariadb start

sleep 2

mariadb -u root -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
mariadb -u root -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
mariadb -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
mariadb -u root -e "FLUSH PRIVILEGES;"

# Import database dump
mariadb -u root $MYSQL_DATABASE < /usr/local/bin/dump.sql

mariadb -u root -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MYSQL_ROOT_PASSWORD');"
mariadb -u root -e "FLUSH PRIVILEGES;"

mariadb -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';"
mariadb -u root -e "FLUSH PRIVILEGES;"

service mariadb stop

exec "$@"