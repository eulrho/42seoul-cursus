USER			= erho

SRC_DIR			= ./srcs
VOL_DIR			= /home/$(USER)/data

WP_NAME			= wordpress
MDB_NAME		= mariadb
NGINX_NAME		= nginx
NETWORK_NAME	= inception

all: volumes host up

volumes:
	sudo mkdir -p ${VOL_DIR}/${WP_NAME}
	sudo docker volume create --driver local --opt type=none --opt device=${VOL_DIR}/${WP_NAME} --opt o=bind ${WP_NAME}
	sudo mkdir -p ${VOL_DIR}/${MDB_NAME}
	sudo docker volume create --driver local --opt type=none --opt device=${VOL_DIR}/${MDB_NAME} --opt o=bind ${MDB_NAME}

host:
	@if ! grep -qFx "127.0.0.1 ${USEr}.42.fr" "/etc/hosts"; then \
		sudo sed -i '2i\127.0.0.1\t${USER}.42.fr' /etc/hosts; \
	fi

up:
	docker-compose -f ${SRC_DIR}/docker-compose.yml up -d --build

down:
	docker-compose -f ${SRC_DIR}/docker-compose.yml down

remove-container:
	@if [ "$(shell docker ps -qa)" ]; then \
		docker stop $(shell docker ps -qa); \
	fi
	@if [ "$(shell docker ps -qa)" ]; then \
		docker rm $(shell docker ps -qa); \
	fi

remove-images:
	@if [ "$(shell docker images -q ${WP_NAME})" ]; then \
		docker rmi ${WP_NAME}; \
	fi
	@if [ "$(shell docker images -q ${MDB_NAME})" ]; then \
		docker rmi ${MDB_NAME}; \
	fi
	@if [ "$(shell docker images -q ${NGINX_NAME})" ]; then \
		docker rmi ${NGINX_NAME}; \
	fi

remove-volumes:
	@if [ "$(shell docker volume ls -q --filter name=${WP_NAME})" ]; then \
		docker volume rm ${WP_NAME}; \
	fi
	@if [ "$(shell docker volume ls -q --filter name=${MDB_NAME})" ]; then \
		docker volume rm ${MDB_NAME}; \
	fi

clean: down remove-container remove-images remove-volumes
	sudo rm -rf /home/$(USER)/data/${WP_NAME}
	sudo rm -rf /home/$(USER)/data/${MDB_NAME}
	@if [ "$(shell docker network ls -q --filter name=${NETWORK_NAME})" ]; then \
		docker network rm ${NETWORK_NAME}; \
	fi

re: clean all

PHONY: all clean re down up remove-container remove-images remove-volumes