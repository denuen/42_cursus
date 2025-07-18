FROM debian:bullseye

RUN apt update -y && apt upgrade -y && \
	apt install -y mariadb-server gettext-base && \
	apt clean && rm -rf /var/lib/apt/lists/*

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY init/init.sql /tmp/init.sql.template
COPY scripts/docker-entrypoint.sh /usr/local/bin/docker-entrypoint.sh

RUN chmod +x /usr/local/bin/docker-entrypoint.sh

VOLUME ["/var/lib/mysql"]

EXPOSE 3306

CMD ["/usr/local/bin/docker-entrypoint.sh"]
