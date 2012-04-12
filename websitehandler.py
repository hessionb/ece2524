#!/usr/bin/python

# # #
# Brian Hession -- March 28, 2012
#
# Testing login functions with python
#
# Class "HokieLogger" logs into hokiespa and retrieves
# course information
#
# March 28, 2012
# Successful login attempt. Python won't keep cookies 
# alive after exiting the program. If anyone has a 
# fix for this, it'd be greatly appreciated.
#
# April 11, 2012
# Searches through html (isn't modular yet). Found a
# way to load cookies used previously. Also changed
# the style of cookies to Mozilla netscape.
#

import cookielib
import urllib
import urllib2
import os
from sys import argv,exit


class HokieLogger(object):

	def __init__(self, login, password):
		"""Initialize"""

		self.login = login
		self.password = password

		# Create cookiejar
		self.jar = cookielib.MozillaCookieJar()

		# Allow redirects, accept cookies, handle http(s)
		self.opener = urllib2.build_opener(
			urllib2.HTTPRedirectHandler(),
			urllib2.HTTPHandler(),
			urllib2.HTTPSHandler(),
			urllib2.HTTPCookieProcessor(self.jar)
		)
		# Add headers to simulate a browser
		self.opener.addheaders = [
			('User-agent', "Mozilla/5.0"),
			('Accept', 'text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5'),
			('Accept-Language', 'en,hu;q=0.8,en-us;q=0.5,hu-hu;q=0.3'),
			('Accept-Encoding', 'gzip, deflate'),
			('Accept-Charset', 'ISO-8859-1,utf-8;q=0.7,*;q=0.7'),
			('Keep-Alive', '300'),
			('Connection', 'keep-alive'),
			('Cache-Control', 'max-age=0')
		]

		try:
			open("cookie.txt",'r')
			self.jar.load("cookie.txt", True, True)
		except:
			self.hokiespalogin()
			# Uncomment to save cookie
			self.jar.save("cookie.txt", True, True)

	def hokiespalogin(self):
		"""Logs in to Hokiespa"""

		# Login website
		loginurl = "https://banweb.banner.vt.edu/ssb/prod/twbkwbis.P_ValLogin"
		# Create post data
		login_data = urllib.urlencode({
			'pid' : self.login,
			'password' : self.password
		})
		# Accept cookie from Hokiespa
		res = self.opener.open("http://hokiespa.vt.edu")
		# Request login
		req = urllib2.Request(loginurl, login_data)
		# Send request and retrieve cookie
		res = self.opener.open(req)
		# print res.read() # Uncomment to make sure login was successful

	def lookupclass(self, crn, term, year, subj, crse):
		"""Course information"""

		# Website for courses
		courseurl = "https://banweb.banner.vt.edu/ssb/prod/HZSKVTSC.P_ProcComments"
		# Post data for course
		course_data = urllib.urlencode({
				'CRN' : crn,
				'TERM' : term,
				'YEAR' : year,
				'SUBJ' : subj,
				'CRSE' : crse,
				'history' : 'N'
		})
		# Request site
		req = urllib2.Request(courseurl, course_data)
		# Send request
		res = self.opener.open(req)
		return res.read(); # Return page

def is_number(num):
	"""Check if string is a number"""
	try:
		float(num)
		return True
	except ValueError:
		return False



if __name__ == "__main__":

	# Input credentials as initial parameters
	if len(argv) < 3:
		print "Run as: " + argv[0] + " <username> <password>"
		exit(1)

	# Login to HokieSpa
	user = HokieLogger( argv[1], argv[2] )
	# Look up class
	page = user.lookupclass( '92164', '09', '2012', 'ECE', '4564' )

	info = []
	for line in page.split('\n'): # Split string into lines
		if '<TD CLASS="mpdefault"style=text-align:center;>' in line:
			info.append(line.strip())

	# Strip extra crap off of the line
	seats = info[3].lstrip('<TD CLASS="mpdefault"style=text-align:center;>').rstrip('</TD>')
	
	# Check if its a number, then check if greater than 0
	if is_number(seats) and seats > 0:
		print "Class open! Num: " + seats
	else:
		print "Not open! Num: " + seats

