FROM debian:bullseye

ARG GRAFANA_VERSION=12.0.2+security-01
ARG DOMAIN_NAME=localhost

RUN apt-get update && apt-get install -y \
	wget \
	libc6-dev \
	libfontconfig1 \
	libfreetype6 \
	fontconfig \
	gnupg2 \
	apt-transport-https \
	software-properties-common \
	ca-certificates \
	curl \
	--no-install-recommends \
	&& mkdir -p /etc/apt/keyrings \
	&& wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor > /etc/apt/keyrings/grafana.gpg \
	&& echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" > /etc/apt/sources.list.d/grafana.list \
	&& apt-get update && apt-get install -y grafana \
	&& mkdir -p /etc/grafana/provisioning/datasources/ \
	&& mkdir -p /etc/grafana/provisioning/dashboards/ \
	&& rm -rf /var/lib/apt/lists/*

COPY ./conf/grafana.ini /etc/grafana/grafana.ini.template
COPY ./provisioning/ /etc/grafana/provisioning/

RUN sed "s/\${DOMAIN_NAME}/$DOMAIN_NAME/g" /etc/grafana/grafana.ini.template > /etc/grafana/grafana.ini

EXPOSE 3000
CMD ["grafana-server", "--homepath=/usr/share/grafana", "--config=/etc/grafana/grafana.ini"]
