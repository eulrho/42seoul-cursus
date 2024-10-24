FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y mariadb-server mariadb-client
RUN rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/lib/mysql /var/run/mysqld
RUN chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
RUN chmod 777 /var/run/mysqld

COPY ./conf/mariadb.conf /etc/mysql/mariadb.conf.d/
RUN chmod +x /etc/mysql/mariadb.conf.d/mariadb.conf

COPY ./tools/init.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init.sh

ENTRYPOINT ["/usr/local/bin/init.sh"]

EXPOSE 3306

CMD ["mysqld"]