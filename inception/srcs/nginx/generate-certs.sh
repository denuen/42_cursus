#!/bin/sh

CERT_DIR="/etc/nginx/certs"
KEY_FILE="$CERT_DIR/inception.key"
CERT_FILE="$CERT_DIR/inception.crt"

# Create the directory if it doesn't exists
mkdir -p "$CERT_DIR"

# Generate the certs only if they don't exist yet
if [ ! -f "$KEY_FILE" ] || [ ! -f "$CERT_FILE" ]; then
  echo "Generating self-signed SSL certificate..."
  openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout "$KEY_FILE" \
    -out "$CERT_FILE" \
    -subj "/C=IT/ST=Lazio/L=Roma/O=42RomaLuiss/CN=${DOMAIN_NAME}"
else
  echo "SSL certificate already exists. Skipping generation."
fi

# Start nginx in foreground with 'daemon off'
exec nginx -g "daemon off;"

