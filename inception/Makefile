IMAGE_NAME=nginx mariadb wordpress

CONTAINER_DIR=srcs/requirements
DOCKERFILE_DIR=$(addprefix $(CONTAINER_DIR)/, $(IMAGE_NAME))
DOCKERFILE=$(addsuffix /Dockerfile, $(DOCKERFILE_DIR))


build:
	docker build -f $(DOCKERFILE) .

run:
	docker run --rm -it $(IMAGE_NAME)

stop:
	docker stop $$(docker ps -q --filter "ancestor=$(IMAGE_NAME)")

clean:
	docker rmi $(IMAGE_NAME) || true

.PHONY: build run stop clean