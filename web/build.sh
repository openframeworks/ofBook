if [ -f /home/ofadmin/ofBook/web/.lock ] || [ ! -f /home/ofadmin/hooks/.regenerate_book ]; then
	exit
fi
touch /home/ofadmin/ofBook/web/.lock
rm /home/ofadmin/hooks/.regenerate_book
cd /home/ofadmin/ofBook/
git pull origin master 
cd scripts
./create_book_linux.sh > logweb.log
retWeb=$?
if [ $retWeb -ne 0 ] 
then
	SUBJECT="Failed building book"
	# Email To ?
	EMAIL="arturo@openframeworks.cc"
	# Email text/message
	# send an email using /bin/mail
	/usr/bin/mail -s "$SUBJECT" "$EMAIL" < buildstate
	cat buildstate
	rm /home/ofadmin/ofBook/web/.lock
	rm /home/ofadmin/ofBook/web/buildstate
	exit
fi
echo copy newsite
cd /home/ofadmin/ofBook
rm -rf /home/ofadmin/openFrameworks.cc/ofBook
mv output/webBook /home/ofadmin/openFrameworks.cc/ofBook
mv output/ofBook.pdf /home/ofadmin/openFrameworks.cc/ofBook/
mv /home/ofadmin/openFrameworks.cc/ofBook/toc.html  /home/ofadmin/openFrameworks.cc/ofBook/index.html
mv scripts/logweb.log /home/ofadmin/openFrameworks.cc/ofBook/
mv scripts/logpdf.log /home/ofadmin/openFrameworks.cc/ofBook/
rm /home/ofadmin/ofBook/web/.lock

