#!/usr/bin/python

# # #
# Brian Hession, Erik Wenkel, James Miller
#
# HokieLogger class module. 
# Logs in to hokieSpa and checks if class 
# is open.
#
#

import cookielib
import urllib
import urllib2
from sys import argv
DIR='ABSDIR'


class HokieLogger(object):


	# # #
	# Constructor
	#
	# Arguments: None
	#
	# Returns HokieLogger object
	#
	#
	def __init__(self):
		"""Initialize"""

		self.cookiedir = DIR + "/etc/cookie.txt"

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


	# # #
	# HokieSpa Login
	#
	# Arguments: login (PID), password
	#
	# Returns: True if Logged in, False if not
	#
	#
	def hokiespalogin(self, login, password):
		"""Logs in to Hokiespa"""

		# Login website
		loginurl = "https://banweb.banner.vt.edu/ssb/prod/twbkwbis.P_ValLogin"
		# Create post data
		login_data = urllib.urlencode({
			'pid' : login,
			'password' : password
		})
		# Accept cookie from Hokiespa
		res = self.opener.open("http://hokiespa.vt.edu")
		# Request login
		req = urllib2.Request(loginurl, login_data)
		# Send request and retrieve cookie
		res = self.opener.open(req)
		
		for line in res.read().split('\n'):
			if 'Welcome,' in line:
				return True
		return False


	# # #
	# Lookup class
	#
	# Arguments: crn, term (Fall=09,Spring=01), year (yyyy),
	#				 subj, crse
	#
	# Returns: Number of seats open in the class, or "Failed"
	#			  if not logged in or cookie expired
	#
	#
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
		return self.checkseats( res.read() ); # Return page


	# # #
	# Check seats
	#
	# Arguments: page (html page split by '\n')
	#
	# Returns Number of seats open in the class, or "Failed"
	#			  if not logged in or cookie expired 
	#
	#
	def checkseats(self, page):
		"""
		Extracts available seats from site and returns True if 
		class is open.
		"""
		info = []
		for line in page.split('\n'): # Split string into lines
			if '<TD CLASS="mpdefault"style=text-align:center;>' in line:
				info.append(line.strip())

		# Strip extra crap off of the line
		seats = info[3].lstrip('<TD CLASS="mpdefault"style=text-align:center;>').lstrip('<B STYLE=color:red;>Full &nbsp;&nbsp;').rstrip('</TD>').rstrip('</B>')

		# Check if its a number, then check if greater than 0
		if len(info) == 5:
			if isnum(seats):
				return seats
		else:
			return "Failed"


	# # #
	# Set Cookie Directory
	#
	# Arguments: directory to new cookie location
	#
	# Returns: Nothing
	#
	#
	def setcookiedir(self, location):
		"""Changes cookie directory"""

		self.cookiedir = location;


	# # #
	# Save cookie
	#
	# Arguments: None
	#
	# Returns: Nothing
	#
	#	
	def savecookie(self):
		"""Saves cookies"""

		self.jar.save(self.cookiedir, True, True)


	# # #
	# Load cookie
	#
	# Arguments: None
	#
	# Returns: True if load was successful, False if not
	#
	#
	def loadcookie(self):
		"""Loads  cookies"""

		try:
			open(self.cookiedir)
		except:
			return False

		self.jar.load(self.cookiedir, True, True)
		return True


# # #
# Is num
#
# Arguments: A string
#
# Returns: True if num is a number, False if not
#
#
def isnum(num):
	"""Check if string is a number"""

	try:
		float(num)
		return True
	except ValueError:
		return False

