DOCKER_COMPOSE_FILE = srcs/docker-compose.yml
#DATA_DIR = /home/denuen/data
DATA_DIR = /Users/denuen/data

all: build up

data-dirs:
	@mkdir -p $(DATA_DIR)/mariadb
	@mkdir -p $(DATA_DIR)/wordpress
	@mkdir -p $(DATA_DIR)/redis
	@mkdir -p $(DATA_DIR)/ftp

build: data-dirs
	docker-compose -f $(DOCKER_COMPOSE_FILE) build

up: data-dirs
	docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

down:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

stop:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down --remove-orphans

clean: down
	docker system prune -a -f
	docker volume prune -f

fclean: clean
	docker-compose -f $(DOCKER_COMPOSE_FILE) down -v --remove-orphans
	docker system prune -a -f --volumes
	sudo rm -rf $(DATA_DIR)

re: fclean all

logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f

status:
	docker-compose -f $(DOCKER_COMPOSE_FILE) ps

nginx-logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f nginx

wordpress-logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f wordpress

mariadb-logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f mariadb

redis-logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f redis

ftp-logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f ftp

adminer-logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f adminer

.PHONY: all build up down clean fclean re logs status nginx-logs wordpress-logs mariadb-logs redis-logs ftp-logs adminer-logs
