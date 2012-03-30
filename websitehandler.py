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
#

import cookielib
import urllib
import urllib2


class HokieLogger(object):

	def __init__(self, login, password):
		"""Initialize"""

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

		# Login
		self.hokiespalogin()
		
		# Uncomment to save cookie
		# self.jar.save("cookie.txt", True, True)

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

if __name__ == "__main__":

	user = HokieLogger( 'username', 'password' )
	#page = user.lookupclass( '92164', '09', '2012', 'ECE', '4564' )
	#print page

