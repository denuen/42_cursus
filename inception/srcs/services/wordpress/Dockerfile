FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y \
	&& apt-get install -y curl php7.4 php7.4-fpm php7.4-mysql mariadb-client \
	&& mkdir -p /run/php \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY scripts/wordpress.sh /usr/local/bin/wordpress.sh

RUN chmod +x /usr/local/bin/wordpress.sh

WORKDIR /var/www/wordpress

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wordpress.sh"]
