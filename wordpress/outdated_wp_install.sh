#!/bin/bash
#Finds outdated wordpress installs
for i in {1..8}; do
find /mnt/u${i}/services/http -wholename '*/wp-includes/version.php' -print -exec grep '$wp_version =' '{}' \;
done
