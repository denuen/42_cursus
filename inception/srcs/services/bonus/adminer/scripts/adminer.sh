#!/bin/bash

curl -sSL https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -o /var/www/adminer/index.php

if [ ! -f /var/www/adminer/index.php ]; then
	echo "Error: Failed to download Adminer"
	exit 1
fi

if ! head -1 /var/www/adminer/index.php | grep -q "<?php"; then
	echo "Error: Downloaded file is not a valid PHP file"
	exit 1
fi

chown -R www-data:www-data /var/www/adminer
chmod -R 755 /var/www/adminer

# Start PHP server
exec php -S 0.0.0.0:8080 -t /var/www/adminer
