#!/bin/sh
rm -rf res/testdata > /dev/null
mkdir -p res/testdata
./gen 10 1000 > 1.in
./gen 10 1000 > 2.in
./gen 10 1000 > 3.in
./gen 10 1000 > 4.in
./gen 100 10000 > 5.in
./gen 100 10000 > 6.in
./gen 100 10000 > 7.in
./gen 100 10000 > 8.in
./gen 500 50000 > 9.in
./gen 500 50000 > 10.in
./gen 500 50000 > 11.in
./gen 500 50000 > 12.in
./gen 1000 100000 > 13.in
./gen 1000 100000 > 14.in
./gen 1000 100000 > 15.in
./gen 1000 100000 > 16.in
./gen 10000 1000000 > 17.in
./gen 10000 1000000 > 18.in
./gen 10000 1000000 > 19.in
./gen 10000 1000000 > 20.in
echo "input done"
i=1
while [ "$i" -le 20 ]; do
	./ans < "$i.in" > "$i.out"
	echo "$i output done"
	i=`expr $i + 1`
done
mv *.in res/testdata
mv *.out res/testdata
