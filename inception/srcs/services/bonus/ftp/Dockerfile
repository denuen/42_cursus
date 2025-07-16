FROM debian:bullseye

RUN apt-get update \
	&& apt-get install -y vsftpd gettext-base \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*

COPY conf/vsftpd.conf /etc/vsftpd.conf.template
COPY scripts/ftp.sh /usr/local/bin/ftp.sh

RUN chmod +x /usr/local/bin/ftp.sh

EXPOSE 21

ENTRYPOINT ["/usr/local/bin/ftp.sh"]
