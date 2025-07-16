#!/bin/bash
set -e

envsubst < /etc/redis/redis.conf.template > /etc/redis/redis.conf

exec redis-server /etc/redis/redis.conf
