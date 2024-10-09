FROM debian:bullseye

ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD

RUN apt update && \
	apt upgrade && \
	apt install -y \
	mariadb-server mariadb-client

RUN mkdir -p /var/lib/mysql /var/run/mysqld
RUN chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
RUN chmod 777 /var/run/mysqld

COPY ./conf/mariadb.cnf /etc/mysql/mariadb.conf.d/
RUN chmod 644 /etc/mysql/mariadb.conf.d/mariadb.cnf
COPY ./conf/dump.sql /usr/local/bin

COPY ./tools/init.sh /usr/local/bin/
RUN bash /usr/local/bin/init.sh

EXPOSE 3306

ENTRYPOINT ["mysqld_safe"]