# FROM debian:buster

# RUN apt update && apt upgrade -y
# RUN apt-get install wget -y

# RUN apt-get install -y php7.3\
# 	php-fpm\
# 	php-mysql\
# 	mariadb-client

# RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

# RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

# RUN		chown -R root:root /var/www/wordpress

# RUN echo "clear_env = no" >> /etc/php/7.3/fpm/php.ini && \
#     echo "listen = wordpress:9000" >> /etc/php/7.3/fpm/pool.d/www.conf


# RUN apt install curl -y
# RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# RUN chmod +x wp-cli.phar
# RUN mv wp-cli.phar /usr/local/bin/wp

# COPY ./tools/config.sh /var/www/html/wp-config/

# Utiliser l'image de base Debian Buster
FROM debian:buster

# Mettre à jour et installer wget
RUN apt-get update && apt-get upgrade -y && \
    apt-get -y install wget

# Installer PHP et ses dépendances
RUN apt-get install -y php7.3 php-fpm php-mysql mariadb-client

# Télécharger WordPress
RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

# Décompresser WordPress et nettoyer
RUN cd /var/www && \
    tar -xzf wordpress-6.0-fr_FR.tar.gz && \
    rm wordpress-6.0-fr_FR.tar.gz

# Changer les permissions du dossier WordPress
RUN chown -R root:root /var/www/wordpress

# Installer WP-CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Copier le script de configuration
COPY tools/auto_config.sh /usr/local/bin/auto_config.sh
RUN chmod +x /usr/local/bin/auto_config.sh

# Créer le dossier pour PHP
RUN mkdir -p /run/php

# Spécifier le point d'entrée pour exécuter le script de configuration
ENTRYPOINT ["/usr/local/bin/auto_config.sh"]

# Lancer php-fpm
CMD ["/usr/sbin/php-fpm7.3", "-F"]
