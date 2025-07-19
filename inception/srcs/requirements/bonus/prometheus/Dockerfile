
FROM debian:bullseye

ARG PROMETHEUS_VERSION=2.52.0
ARG PROMETHEUS_USER=prometheus
ARG PROMETHEUS_GROUP=prometheus

WORKDIR /prometheus

RUN apt-get update \
    && apt-get install -y --no-install-recommends wget ca-certificates \
    && groupadd --system $PROMETHEUS_GROUP \
    && useradd --no-create-home --system --shell /usr/sbin/nologin -g $PROMETHEUS_GROUP $PROMETHEUS_USER \
    && mkdir -p /etc/prometheus /var/lib/prometheus \
    && cd /tmp \
    && wget https://github.com/prometheus/prometheus/releases/download/v${PROMETHEUS_VERSION}/prometheus-${PROMETHEUS_VERSION}.linux-amd64.tar.gz \
    && tar -xzf prometheus-${PROMETHEUS_VERSION}.linux-amd64.tar.gz \
    && cd prometheus-${PROMETHEUS_VERSION}.linux-amd64 \
    && mv prometheus promtool /usr/local/bin/ \
    && mv consoles console_libraries /etc/prometheus/ \
    && mv prometheus.yml /etc/prometheus/ \
    && chown -R $PROMETHEUS_USER:$PROMETHEUS_GROUP /usr/local/bin/prometheus /usr/local/bin/promtool /etc/prometheus /var/lib/prometheus \
    && rm -rf /tmp/* \
    && apt-get remove -y wget \
    && apt-get autoremove -y \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

EXPOSE 9090

ENTRYPOINT ["/usr/local/bin/prometheus"]
CMD ["--config.file=/etc/prometheus/prometheus.yml", "--storage.tsdb.path=/var/lib/prometheus"]
