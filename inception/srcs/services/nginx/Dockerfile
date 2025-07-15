FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx openssl \
	&& groupadd -g 101 nginx \
	&& useradd -u 101 -g nginx -s /bin/false -M nginx \
	&& mkdir -p /var/log/nginx /var/cache/nginx /run/nginx \
	&& chown -R nginx:nginx /var/log/nginx /var/cache/nginx /run/nginx \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY scripts/generate-certs.sh /usr/local/bin/generate-certs.sh
RUN chmod +x /usr/local/bin/generate-certs.sh

WORKDIR /var/www/wordpress
EXPOSE 443

ENTRYPOINT ["sh", "/usr/local/bin/generate-certs.sh"]
