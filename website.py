#!/usr/bin/python

from sys import argv, exit
from urllib import urlretrieve

if len(argv) != 3:
	print "Use in following format: " + argv[0] + " <URL> <FILENAME>"
	exit(1)

try:
	results = urlretrieve( str(argv[1]), str(argv[2]) )
except:
	print "Error connecting to URL"

