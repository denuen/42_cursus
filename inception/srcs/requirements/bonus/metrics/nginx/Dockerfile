FROM debian:bullseye

ARG NGINX_EXPORTER_VERSION=0.11.0
ARG NGINX_EXPORTER_USER=exporter
ENV BIN_PATH=/usr/local/bin

RUN apt-get update && \
	apt-get install -y --no-install-recommends wget ca-certificates && \
	rm -rf /var/lib/apt/lists/*

RUN useradd --no-create-home --shell /usr/sbin/nologin $NGINX_EXPORTER_USER

RUN wget https://github.com/nginxinc/nginx-prometheus-exporter/releases/download/v${NGINX_EXPORTER_VERSION}/nginx-prometheus-exporter_${NGINX_EXPORTER_VERSION}_linux_amd64.tar.gz && \
	tar -xzf nginx-prometheus-exporter_${NGINX_EXPORTER_VERSION}_linux_amd64.tar.gz && \
	mv nginx-prometheus-exporter $BIN_PATH/nginx-prometheus-exporter && \
	rm nginx-prometheus-exporter_${NGINX_EXPORTER_VERSION}_linux_amd64.tar.gz

RUN chown $NGINX_EXPORTER_USER:$NGINX_EXPORTER_USER $BIN_PATH/nginx-prometheus-exporter

EXPOSE 9113

USER $NGINX_EXPORTER_USER

ENTRYPOINT ["/bin/sh", "-c", "$BIN_PATH/nginx-prometheus-exporter -nginx.scrape-uri=$NGINX_STATUS_URL"]
