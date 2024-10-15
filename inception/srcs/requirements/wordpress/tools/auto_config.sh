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
wp user create second_user second_user@example.com --role=editor --user_pass=second_password --allow-root --path='/var/www/wordpress'
