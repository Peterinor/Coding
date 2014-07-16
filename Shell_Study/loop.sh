#!/bin/sh
for i in jpg/*.jpg; 
do 
	echo "converting $i ...";
	convert -resize 30%x30% "$i" "$i.png";
	sudo chmod 777 "$i.png";
done
