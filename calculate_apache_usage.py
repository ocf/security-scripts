#!/usr/bin/python
import sys
import operator

f = open(sys.argv[1],'r')

line = f.readline()
user_dict = dict()
while (line != ""):
	line_lst = line.split(' ')
	if line_lst[8] == "200" or line_lst[8] == 204:
		if len(line_lst) > 10:
			if line_lst[6].find("~") > 0:
				username = line_lst[6].split("/")[1].strip("~")
				size_str = line_lst[9]
				if size_str == "-":
					size_str = 0

				if username in user_dict:
					user_dict[username] += long(size_str)
				else:
					user_dict[username] = long(size_str)
	line = f.readline()

sorted_names = sorted(user_dict.iteritems(), key=operator.itemgetter(1))

for name in sorted_names:
	print(name[0] + " " + str(name[1]/1024.0/1024.0) + "MB")
