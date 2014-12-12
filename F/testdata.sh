#!/bin/sh
rm -rf res/testdata > /dev/null
mkdir -p res/testdata
./gen 10 10 > 1.in
./gen 10 100 > 2.in
./gen 10 1000 > 3.in
./gen 10 1000 > 4.in
./gen 50 10 > 5.in
./gen 50 100 > 6.in
./gen 50 1000 > 7.in
./gen 50 1000 > 8.in
./gen 500 10 > 9.in
./gen 500 100 > 10.in
./gen 500 1000 > 11.in
./gen 500 1000 > 12.in
./gen 2000 10 > 13.in
./gen 2000 100 > 14.in
./gen 2000 1000 > 15.in
./gen 2000 1000 > 16.in
./gen 20000 10 > 17.in
./gen 20000 100 > 18.in
./gen 20000 1000 > 19.in
./gen 20000 1000 > 20.in
echo "input done"
i=1
while [ "$i" -le 20 ];do
	./ans < "$i.in" > "$i.out"
	echo "$i output done"
	i=`expr $i + 1`
done
mv *.in res/testdata
mv *out res/testdata
