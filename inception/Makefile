USER			= erho

SRC_DIR			= ./srcs
VOL_DIR			= /home/$(USER)/data

WP_NAME			= wordpress
MDB_NAME		= mariadb
STAT_NAME		= static

all: volumes hosts up

volumes:
	# sudo mkdir -p ${VOL_DIR}/${WP_NAME}
	# sudo docker volume create --driver local --opt type=none --opt device=${VOL_DIR}/${WP_NAME} --opt o=bind ${WP_NAME}
	sudo mkdir -p ${VOL_DIR}/${MDB_NAME}
	sudo docker volume create --driver local --opt type=none --opt device=${VOL_DIR}/${MDB_NAME} --opt o=bind ${MDB_NAME}
	# sudo mkdir -p ${VOL_DIR}/${STAT_NAME}
	# sudo docker volume create --driver local --opt type=none --opt device=${VOL_DIR}/${STAT_NAME} --opt o=bind ${STAT_NAME}

hosts:
	@if ! grep -qFx "127.0.0.1 ${USER}.42.fr" /etc/hosts; then \
		sudo sed -i '2i\127.0.0.1\t${USER}.42.fr' /etc/hosts; \
	fi

up:
	docker-compose -f ${SRC_DIR}/docker-compose.yml up -d --build

down:
	docker-compose -f ${SRC_DIR}/docker-compose.yml down

clean: down
	# docker volume rm ${WP_NAME}
	# sudo rm -rf /home/$(USER)/data/${WP_NAME}
	docker volume rm ${MDB_NAME}
	sudo rm -rf /home/$(USER)/data/${MDB_NAME}
	# docker volume rm ${STAT_NAME}
	# sudo rm -rf /home/$(USER)/data/${STAT_NAME}
	# sudo sed -i '/127\.0\.0\.1\t${USER}\.42\.fr/d' /etc/hosts

re: down all

prepare: update compose

update:
	sudo apt -y update && sudo apt -y upgrade
	@if [ $$? -eq 0 ]; then \
		sudo apt -y install docker.io; \
		sudo chmod 666 /var/run/docker.sock; \
	fi

compose:
	sudo apt -y install curl
	sudo curl -SL https://github.com/docker/compose/releases/download/v2.2.3/docker-compose-linux-x86_64 -o /usr/local/bin/docker-compose
	sudo chmod +x /usr/local/bin/docker-compose

PHONY: all clean re prepare