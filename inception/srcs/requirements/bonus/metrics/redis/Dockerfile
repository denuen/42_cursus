FROM debian:bullseye

RUN apt-get update && apt-get install -y wget ca-certificates \
	&& groupadd --system redis_exporter \
	&& useradd -s /sbin/nologin --system -g redis_exporter redis_exporter

ENV REDIS_EXPORTER_VERSION=1.61.0

RUN wget https://github.com/oliver006/redis_exporter/releases/download/v${REDIS_EXPORTER_VERSION}/redis_exporter-v${REDIS_EXPORTER_VERSION}.linux-amd64.tar.gz \
	&& tar xvf redis_exporter-v${REDIS_EXPORTER_VERSION}.linux-amd64.tar.gz \
	&& mv redis_exporter-v${REDIS_EXPORTER_VERSION}.linux-amd64/redis_exporter /usr/local/bin/ \
	&& rm -rf redis_exporter-v${REDIS_EXPORTER_VERSION}.linux-amd64*

USER redis_exporter

COPY entrypoint.sh /entrypoint.sh
USER root
RUN chmod +x /entrypoint.sh
USER redis_exporter

ENTRYPOINT ["/entrypoint.sh"]
