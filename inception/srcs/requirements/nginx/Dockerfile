FROM debian:bullseye

RUN apt update && \
	apt install -y nginx && \
	apt clean && \
	apt -rf /var/lib/apt/lists/*

COPY ./tools/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]