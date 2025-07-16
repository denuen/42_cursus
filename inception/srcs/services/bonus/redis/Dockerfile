FROM debian:bullseye

RUN apt-get update && apt-get install -y redis-server gettext-base \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY conf/redis.conf /etc/redis/redis.conf.template
COPY scripts/redis.sh /usr/local/bin/redis.sh

RUN chmod +x /usr/local/bin/redis.sh

RUN mkdir -p /var/lib/redis && \
	chown redis:redis /var/lib/redis

USER redis
WORKDIR /var/lib/redis

EXPOSE 6379

CMD ["redis-server", "/etc/redis/redis.conf"]
ENTRYPOINT ["/usr/local/bin/redis.sh"]
