#!/bin/bash

if [ -n "$REDIS_PASSWORD" ]; then
	REDIS_URL="redis://:${REDIS_PASSWORD}@redis:6379"
else
	REDIS_URL="redis://redis:6379"
fi

exec /usr/local/bin/redis_exporter --redis.addr="$REDIS_URL"
