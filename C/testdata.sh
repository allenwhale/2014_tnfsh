#!/bin/sh
rm -rf res/testdata > /dev/null
mkdir -p res/testdata
./gen 100 10 > 1.in
./gen 100 10 > 2.in
./gen 100 10 > 3.in
./gen 100 10 > 4.in
./gen 500 100 > 5.in
./gen 500 100 > 6.in
./gen 500 100 > 7.in
./gen 500 100 > 8.in
./gen 1000 100 > 9.in
./gen 1000 100 > 10.in
./gen 1000 100 > 11.in
./gen 1000 100 > 12.in
./gen 10000 1000 > 13.in
./gen 10000 1000 > 14.in
./gen 10000 1000 > 15.in
./gen 10000 1000 > 16.in
./gen 100000 10000 > 17.in
./gen 100000 10000 > 18.in
./gen 100000 10000 > 19.in
./gen 100000 10000 > 20.in
echo "input done"
i=1
while [ "$i" -le 20 ]; do
	./ans < "$i.in" > "$i.out"
	echo "$i output done"
	i=`expr $i + 1`
done
mv *.in res/testdata
mv *.out res/testdata
