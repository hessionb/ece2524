#!/usr/bin/python

from urllib import urlretrieve

def get( URL, FILENAME ):
	"""get( URL, FILENAME )
	Downloads the given website (URL) and saves it in FILENAME"""
	try:
		results = urlretrieve( str(URL), str(FILENAME) )
	except:
		print "Error connecting to URL"
	
if __name__ == "__main__":

	get( "http://www.google.com", "website.html" )
	
