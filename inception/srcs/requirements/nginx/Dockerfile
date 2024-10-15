FROM debian:latest

RUN apt-get update && \
    apt-get install -y nginx openssl && \
    apt-get clean && \
	apt install vim -y && \
	apt install curl -y

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=onault.42.fr/UID=onault"

RUN chmod 755 /var/www/html && chown -R www-data:www-data /var/www/html

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

CMD ["nginx", "-g", "daemon off;"]
