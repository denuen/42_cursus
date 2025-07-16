FROM debian:bullseye

RUN apt-get update \
	&& apt-get install -y php7.4 php7.4-mysql curl unzip \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/adminer

COPY scripts/adminer.sh /usr/local/bin/adminer.sh
RUN chmod +x /usr/local/bin/adminer.sh

EXPOSE 8080

WORKDIR /var/www/adminer

ENTRYPOINT ["/usr/local/bin/adminer.sh"]
