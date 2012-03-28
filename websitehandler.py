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
# March 28, 2012
# Successful login attempt. Cookie saved as "cookie.txt" in
# same directory

import cookielib
import urllib
import urllib2
	
url = "https://banweb.banner.vt.edu/ssb/prod/twbkwbis.P_ValLogin"

class HokieLogger(object):
	
	def __init__(self, login, password):
		"""Initializing"""
		
		self.login = login
		self.password = password
		
		# Create cookiejar
		self.jar = cookielib.LWPCookieJar()
		
		# Allow redirects, accept cookies, handle http(s)
		self.opener = urllib2.build_opener(
			urllib2.HTTPRedirectHandler(),
			urllib2.HTTPHandler(),
			urllib2.HTTPSHandler(),
			urllib2.HTTPCookieProcessor(self.jar)
		)
		# Add a firefox header to fool website
		self.opener.addheaders = [('User-agent', "Mozilla/5.0")]
		
		self.hokiespalogin()
		
		# Save cookie
		self.jar.save("cookie.txt", True, True)
		
	def hokiespalogin(self):
		"""Logs in to Hokiespa"""
		
		# Create post data
		login_data = urllib.urlencode({
			'pid' : self.login,
			'password' : self.password
		})
		# Accept initial cookie
		res = self.opener.open("http://hokiespa.vt.edu")
		# Request login
		req = urllib2.Request(url, login_data)
		# Send request
		page = self.opener.open(req)
		print page.read() # Read to make sure login was successful

if __name__ == "__main__":

	user = HokieLogger( 'user', 'password' )

