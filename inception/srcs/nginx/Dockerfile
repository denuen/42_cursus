FROM debian:bullseye

RUN apt-get update \ 
    && apt-get install -y nginx openssl \
	&& groupadd -g 101 nginx \
	&& useradd -u 101 -g 101 -s /bin/false nginx \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /var/log/nginx /var/cache/nginx \
    && chown -R nginx:nginx /var/log/nginx /var/cache/nginx

COPY nginx.conf /etc/nginx/nginx.conf
COPY generate-certs.sh /usr/local/bin/generate-certs.sh
RUN chmod +x /usr/local/bin/generate-certs.sh

WORKDIR /var/www/html
EXPOSE 443

ENTRYPOINT ["sh", "/usr/local/bin/generate-certs.sh"]
