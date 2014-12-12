#!/bin/sh
rm -rf res/testdata > /dev/null
mkdir -p res/testdata
./gen 5 25 50 10 > 1.in
./gen 5 10 70 25 > 2.in
./gen 5 20 70 25 > 3.in
./gen 5 25 150 25 > 4.in
./gen 10 50 70 50 > 5.in
./gen 10 60 200 60 > 6.in
./gen 10 70 1000 70 > 7.in
./gen 10 100 200 100 > 8.in
./gen 20 100 70 100 > 9.in
./gen 20 150 100 150 > 10.in
./gen 20 300 300 300 > 11.in
./gen 20 400 500 400 > 12.in
./gen 50 1000 100 1000 > 13.in
./gen 50 1500 200 1500 > 14.in
./gen 50 2000 500 2000 > 15.in
./gen 50 2500 700 2500 > 16.in
./gen 100 5000 100 5000 > 17.in
./gen 100 7000 300 7000 > 18.in
./gen 100 8000 700 8000 > 19.in
./gen 100 10000 900 10000 > 20.in
echo "inout done"
i=1
while [ "$i" -le 20 ];do
	./ans < "$i.in" > "$i.out"
	echo "$i output done"
	i=`expr $i + 1`
done
mv *.in res/testdata
mv *.out res/testdata
