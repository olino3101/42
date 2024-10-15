FROM debian:buster

RUN apt update -y && \
	apt upgrade -y && \
	apt-get install mariadb-server -y
	RUN apt-get update && apt-get install -y sudo
	COPY conf/mariadb.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
	COPY ./tools/init_mysql.sh /
	RUN chmod +x /init_mysql.sh

	USER root
	CMD ["/bin/bash", "/init_mysql.sh"]
	# CMD ["/init_mysql.sh"]
