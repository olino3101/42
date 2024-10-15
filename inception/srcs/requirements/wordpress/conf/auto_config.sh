#!/bin/bash

# Attendre que MariaDB démarre
sleep 10

# Vérifier si wp-config.php existe déjà
if [ ! -f /var/www/wordpress/wp-config.php ]; then
    # Créer la configuration WordPress
    wp config create --allow-root \
        --dbname=$MYSQL_DATABASE \
        --dbuser=$MYSQL_USER \
        --dbpass=$MYSQL_PASSWORD \
        --dbhost=mariadb:3306 --path='/var/www/wordpress'
fi

# Installer WordPress et ajouter un utilisateur
wp core install --allow-root \
    --url='http://onault.42.fr' \
    --title='Titre du Site' \
    --admin_user=$MYSQL_USER \
    --admin_password=$MYSQL_PASSWORD \
    --admin_email='email@example.com' \
    --path='/var/www/wordpress'

# Créer un deuxième utilisateur
wp user create ${WP_USER $WP_MAIL} --role=${WP_ROLE} --user_pass=${WP_PASSWORD} --allow-root --path='/var/www/wordpress'
!/bin/sh

exec /usr/sbin/php-fpm7.4 -F


# if [ -f "/var/www/jamrabhi/wordpress/wp-config.php" ]
# then 

# sleep 5

# else

# sleep 20
# curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# chmod +x wp-cli.phar
# mv wp-cli.phar /usr/local/bin/wp
# wp core download --allow-root --version=6.4 --path=/var/www/jamrabhi/wordpress
# cd /var/www/jamrabhi/wordpress
# wp config create --allow-root --dbname=${SQL_DATABASE} --dbuser=${SQL_USER} --dbpass=${SQL_PASSWORD} --dbhost="mariadb"
# wp core install --allow-root --url=${DOMAIN_NAME} --title=${WP_TITLE} --admin_user=${SQL_USER} --admin_password=${SQL_PASSWORD} --admin_email=${WP_EMAIL} --skip-email
# wp user create --allow-root ${WP_EDITOR_LOGIN} ${WP_EDITOR_MAIL} --role=${WP_EDITOR_ROLE} --user_pass=${WP_EDITOR_PASS}

# fi
