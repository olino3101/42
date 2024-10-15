FROM debian:latest

# Install Nginx and OpenSSL
RUN apt-get update && \
    apt-get install -y nginx openssl && \
    apt-get clean && \
	apt install vim -y && \
	apt install curl -y
    #rm -rf /var/lib/apt/lists/*

# Create directories for SSL certificates
# RUN mkdir -p /etc/ssl/private /etc/ssl/certs real
RUN mkdir -p /etc/nginx/ssl
# Generate a self-signed SSL certificate and key
# RUN openssl req -newkey rsa:2048 -nodes -keyout /etc/ssl/private/nginx-selfsigned.key -x509 -days 365 -out /etc/ssl/certs/nginx-selfsigned.crt \
#     -subj "/C=US/ST=State/L=City/O=Organization/OU=Unit/CN=localhost"
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=onault.42.fr/UID=onault"
# RUN mkdir -p /var/run/nginx
RUN chmod 755 /var/www/html && chown -R www-data:www-data /var/www/html

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

# Expose port 443
# EXPOSE 443

# Start Nginx
CMD ["nginx", "-g", "daemon off;"]
