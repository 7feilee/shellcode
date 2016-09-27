__Shell Storm :: Shell Code Repository__
================

_Caleb Stewart_ | _Monday, January 18th, 2016_

----------------

[`Shell Storm`](shellstorm) has put out a large and useful list of shell code's for various platforms and architectures. Sadly, we are not always able to access the shell storm webpage due to angry firewalls blocking "hacking" related webpages (*cough* *cough* barracuda... *cough* *cough*). Due to this, I have whipped up a little python script to scrape all of the shell codes from the website and save them within the repository.

The different codes are organized first by system type, then by architecture, and lastly by what they actually do. For example, if you are running on an x86-64 Ubuntu machine (most likely) and would like some shell code to run execve("/bin/sh",0), then you can look under `Linux/x86-64` and you might find a file called [`execve(-bin-sh);.c`](linux_x64_execve). Due to the way the files were hosted, I was unable to decipher what the filetype was. Most of them were in `C`, therefore all files have a '.c' extension (sorry, the best I could do), but you should open the file before trying to compile it. Normally, the files will have the shell code in a hex-escaped string, as well as the disassembly in a comment. 

The [`scrape script`](scrape_script) will simply query the main page of Shell Storm's shell code repository and scrape the different shell codes from the page. It will completely rebuild the directory structure. If the page is updated, this script would (very inefficiently) update this local copy.

[shellstorm]: http://shell-storm.org
[linux_x64_execve]: /shell-storm/Linux/x86-64/execve(-bin-sh);.c
[scrape_script]: /shell-storm/scrape.py