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
# Searches through html. Found a way to load cookies 
# used previously. Also changed the style of cookies 
# to Mozilla netscape.
#
#
#

import cookielib
import urllib
import urllib2
from sys import argv,exit



class HokieLogger(object):

	def __init__(self, login, password):
		"""Initialize"""

		self.login = login
		self.password = password
		self.cookiedir = "cookie.txt"

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
			('Keep-Alive', '300'),
			('Connection', 'keep-alive'),
			('Cache-Control', 'max-age=0')
		]

		try:
			open(self.cookiedir,'r') # Check for existing cookies
			print "Loading cookies...",
			self.jar.load(self.cookiedir, True, True) # Load
			# Check if cookie expired
			for cookie in self.jar:
				if cookie.is_expired():
					print "expired. Relogging...",
					self.hokiespalogin()
					break
			print "done."
		except:
			print "Relogging...",
			self.hokiespalogin() # Logs in if no cookies
			# Uncomment to save cookie
			self.jar.save(self.cookiedir, True, True) # Saves
			print "done."

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

	def checkSeats(self, page):
		"""
		Extracts available seats from site and returns True if 
		class is open.
		"""
		info = []
		for line in page.split('\n'): # Split string into lines
			if '<TD CLASS="mpdefault"style=text-align:center;>' in line:
				info.append(line.strip())

		# Strip extra crap off of the line
		seats = info[3].lstrip('<TD CLASS="mpdefault"style=text-align:center;>').rstrip('</TD>')

		# Check if its a number, then check if greater than 0
		if len(info) == 5 and isnum(seats) and seats > 0:
			return True
		else:
			return False

	def setCookieDir(self, location):
		"""Changes cookie directory"""

		self.cookiedir = location;



def isnum(num):
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
	print "Looking up class...",
	page = user.lookupclass( '92164', '09', '2012', 'ECE', '4564' )
	print "done."

	# Checks if class is open
	if user.checkSeats(page):
		print "Class open!"
	else:
		print "Class closed!"

