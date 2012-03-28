#!/usr/bin/python

# # #
# Brian Hession -- March 28, 2012
#
# Testing login functions with python
#
# STEPS TO LOGIN TO HOKIESPA
# go to hokiespa.vt.edu, follow redirects, and save cookie
# load cookie, attepmt login, and follow redirects
# --resave cookie?
#

import urllib2, cookielib

def start_session( URL ):
	"""Starts a cookie session"""
	
	# Makes a cookiejar
	jar = cookielib.LWPCookieJar("cookies")
	
	# Builds an opener to handle cookies and redirects
	opener = urllib2.build_opener( urllib2.HTTPCookieProcessor(jar), urllib2.HTTPRedirectHandler() )
	
	# Opens url
	response = opener.open( URL )
	
	# Saves cookie to cookie.txt
	jar.save("cookie.txt", True, True)
	
if __name__ == "__main__":
	
	URL = "http://www.hokiespa.vt.edu"
	start_session( URL );
	
