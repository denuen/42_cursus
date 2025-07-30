#!/bin/bash
set -e

envsubst < /tmp/init.sql.template > /tmp/init.sql

# Initialize database only if it not exists
if [ ! -d "/var/lib/mysql/mysql" ]; then
	mysql_install_db --user=mysql --datadir=/var/lib/mysql --rpm
fi

# Starts mysql in background
mysqld_safe --datadir=/var/lib/mysql --nowatch &

# Wait mysql start
attempt_counter=0
max_attempts=30
until mysqladmin ping --silent; do
	if [ ${attempt_counter} -eq ${max_attempts} ]; then
		echo "Error: Could not connect to MySQL."
		exit 1
	fi
	attempt_counter=$((attempt_counter+1))
	sleep 1
done

mysql < /tmp/init.sql

mysqladmin shutdown -u root -p${MYSQL_ROOT_PASSWORD}

# Start MySQL in foreground
exec mysqld_safe --datadir=/var/lib/mysql
