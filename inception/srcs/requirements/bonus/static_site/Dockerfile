FROM debian:bullseye

RUN apt-get update \
	&& apt-get install -y nginx \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY ./site /var/www/static_site
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]
