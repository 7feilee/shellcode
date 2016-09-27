#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: caleb
# @Date:   2016-01-17 22:24:55
# @Last Modified by:   caleb
# @Last Modified time: 2016-01-17 23:51:16
import requests
import os
import HTMLParser
from bs4 import BeautifulSoup

url = 'http://shell-storm.org'

print "Scraping shell code from the shell-storm shellcode database..."

parser = BeautifulSoup(requests.get(url + '/shellcode').text, 'html.parser')

for anchor in parser.find_all('a'):
	if( anchor.get('href').startswith('/shellcode/files/shellcode') ):
		names = anchor.get_text().split(' - ')
		directory = names[0].replace(' ', '_')
		filename = names[1].replace('/', '-').replace(' ', '_') + '.c'
		os.system('mkdir -p "' + directory + '"');
		content = requests.get(url + anchor.get('href')).text
		content = HTMLParser.HTMLParser().unescape(content);
		content = content.split('<pre>')[1].split('<body>')[0].strip()
		f = open(directory + '/' + filename, 'wb')
		f.write(content.encode('utf-8'))
		f.close()
		print '"' + anchor.get('href') + '" -> "' + directory + '/' + filename + '"'
