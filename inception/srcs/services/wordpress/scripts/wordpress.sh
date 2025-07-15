#!/bin/bash
set -e

REQUIRED_VARS=(
	DOMAIN_NAME SITE_TITLE
	MYSQL_DATABASE MYSQL_USER MYSQL_PASSWORD
	WP_ADMIN_USER WP_ADMIN_PASSWORD WP_ADMIN_EMAIL
	WP_USER WP_USER_EMAIL WP_USER_PASSWORD
)

for var in "${REQUIRED_VARS[@]}"; do
	if [ -z "${!var}" ]; then
		echo "Error: Required environment variable '$var' is not set."
		exit 1
	fi
done

if echo "$WP_ADMIN_USER" | grep -iqE 'admin|administrator'; then
	echo "Error: Administrator username cannot contain 'admin' or 'administrator'."
	exit 1
fi

mkdir -p /var/www/wordpress
cd /var/www/wordpress

# If it doesn't exists, install WP CLI
if [ ! -f /usr/local/bin/wp ]; then
	curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x /usr/local/bin/wp
fi

# If wp-config.php doesn't exists, download WP e create config
if [ ! -f wp-config.php ]; then
	wp core download --allow-root
	wp config create \
		--dbname="${MYSQL_DATABASE}" \
		--dbuser="${MYSQL_USER}" \
		--dbpass="${MYSQL_PASSWORD}" \
		--dbhost="mariadb" \
		--path=/var/www/wordpress \
		--allow-root
fi

echo "Waiting for database connection..."
attempt_counter=0
max_attempts=30
until mysqladmin ping -h mariadb --silent; do
	if [ ${attempt_counter} -eq ${max_attempts} ]; then
		echo "Error: Could not connect to database."
		exit 1
	fi
	attempt_counter=$((attempt_counter+1))
	sleep 1
done

# If Wordpress is not installed, it execute an auto-installation
if ! wp core is-installed --allow-root; then
	if echo "${WP_ADMIN_USER}" | grep -iE 'admin|administrator' >/dev/null; then
		echo "Error: Administrator username cannot contain 'admin' or 'administrator'."
		exit 1
	fi

	wp core install \
		--url="${DOMAIN_NAME}" \
		--title="${SITE_TITLE}" \
		--admin_user="${WP_ADMIN_USER}" \
		--admin_password="${WP_ADMIN_PASSWORD}" \
		--admin_email="${WP_ADMIN_EMAIL}" \
		--skip-email \
		--allow-root

	wp user create \
		"${WP_USER}" "${WP_USER_EMAIL}" \
		--user_pass="${WP_USER_PASSWORD}" \
		--role=editor \
		--allow-root
fi

php-fpm7.4 -F
