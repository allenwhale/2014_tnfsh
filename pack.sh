#!/bin/sh
all="A B C D E F G"
IFS=" "
rm -rf "dist" > /dev/null
mkdir "dist"
for i in $all ;do
	rm -f  "$i/$i.tar.xz"
	rm -rf "$i/http" > /dev/null
	mkdir "$i/http"
	cp "$i/cont.html" "$i/http"
	cd "$i"
	tar Jcvf "../dist/$i.tar.xz" "res" "http" "conf.json"
	cd ..
done
