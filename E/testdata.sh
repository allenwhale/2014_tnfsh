#!/bin/sh
rm -rf res/testdata > /dev/null
mkdir -p res/testdata
./gen 10 10 > 1.in
./gen 10 50 > 2.in
./gen 10 60 > 3.in
./gen 10 100 > 4.in
./gen 50 50 > 5.in
./gen 50 500 > 6.in
./gen 50 2000 > 7.in
./gen 50 2500 > 8.in
./gen 100 100 > 9.in
./gen 100 1000 > 10.in
./gen 100 5000 > 11.in
./gen 100 10000 > 12.in
./gen 500 500 > 13.in
./gen 500 5000 > 14.in
./gen 500 50000 > 15.in
./gen 500 250000 > 16.in
./gen 1000 1000 > 17.in
./gen 1000 10000 > 18.in
./gen 1000 100000 > 19.in
./gen 1000 1000000 > 20.in
echo "input done"
i=1
while [ "$i" -le 20 ]; do
	./ans < "$i.in" > "$i.out"
	echo "$i output done"
	i=`expr $i + 1`
done
mv *.in res/testdata
mv *.out res/testdata

