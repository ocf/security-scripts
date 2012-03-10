#!/usr/bin/bash

#finds wp-config files that are insecure and dumps the database password to the terminal to be tested later
find /mnt/$1/services/http/ -wholename 'wp-config.php' -print -exec grep 'DB_PASSWORD' '{}' \;
