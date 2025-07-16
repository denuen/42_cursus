#!/bin/bash

envsubst < /etc/vsftpd.conf.template > /etc/vsftpd.conf

useradd -m ${FTP_USER}
echo "${FTP_USER}:${FTP_PASSWORD}" | chpasswd

mkdir -p /home/${FTP_USER}/ftp/files
chown -R ${FTP_USER}:${FTP_USER} /home/${FTP_USER}/ftp
chmod -R 755 /home/${FTP_USER}/ftp

mkdir -p /var/run/vsftpd/empty

exec /usr/sbin/vsftpd /etc/vsftpd.conf
