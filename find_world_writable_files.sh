#!/bin/bash
#Finds files that are world writable in the OCF
find /mnt/ \( -perm -o+w -o \( -perm -g+w -group ocf \) \) \( -type f -o -type d -o -type p -o -type s \) -print 2> /dev/null
