FROM debian:bullseye

ARG MARIADB_EXPORTER_VERSION=0.15.0
ARG MARIADB_EXPORTER_USER=mariadb_exporter
ARG MARIADB_EXPORTER_GROUP=mariadb_exporter

RUN apt-get update && apt-get install -y wget ca-certificates \
	&& groupadd --system ${MARIADB_EXPORTER_GROUP} \
	&& useradd --no-create-home --system --shell /usr/sbin/nologin -g ${MARIADB_EXPORTER_GROUP} ${MARIADB_EXPORTER_USER} \
	&& mkdir /app \
	&& cd /tmp \
	&& wget https://github.com/prometheus/mysqld_exporter/releases/download/v${MARIADB_EXPORTER_VERSION}/mysqld_exporter-${MARIADB_EXPORTER_VERSION}.linux-amd64.tar.gz \
	&& tar -xzf mysqld_exporter-${MARIADB_EXPORTER_VERSION}.linux-amd64.tar.gz \
	&& mv mysqld_exporter-${MARIADB_EXPORTER_VERSION}.linux-amd64/mysqld_exporter /usr/local/bin/ \
	&& rm -rf /tmp/* \
	&& mkdir -p /etc/mysqld_exporter \
	&& chown -R ${MARIADB_EXPORTER_USER}:${MARIADB_EXPORTER_GROUP} /etc/mysqld_exporter /app \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY ./conf/.my.cnf /etc/mysqld_exporter/.my.cnf

USER ${MARIADB_EXPORTER_USER}

EXPOSE 9104

ENTRYPOINT ["/usr/local/bin/mysqld_exporter"]

CMD ["--config.my-cnf=/etc/mysqld_exporter/.my.cnf"]
