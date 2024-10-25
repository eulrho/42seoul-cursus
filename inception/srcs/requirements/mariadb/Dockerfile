FROM debian:bullseye

# RUN hwclock --hctosys
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y mariadb-server mariadb-client
RUN rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/lib/mysql
RUN chown -R mysql:mysql /var/lib/mysql

COPY ./conf/mariadb.cnf /etc/mysql/mariadb.conf.d/
RUN chmod +x /etc/mysql/mariadb.conf.d/mariadb.cnf

COPY ./tools/init.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init.sh

ENTRYPOINT ["/usr/local/bin/init.sh"]

EXPOSE 3306

CMD ["mysqld"]