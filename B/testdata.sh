#!/bin/sh
rm -rf res/testdata > /dev/null
mkdir -p res/testdata
./gen 10 1000 > 1.in
./gen 20 2000 > 2.in
./gen 50 5000 > 3.in
./gen 100 10000 > 4.in
./gen 200 20000 > 5.in
./gen 300 30000 > 6.in
./gen 400 40000 > 7.in
./gen 500 50000 > 8.in
./gen 1000 100000 > 9.in
./gen 2000 200000 > 10.in
./gen 5000 500000 > 11.in
./gen 6000 600000 > 12.in
./gen 7000 700000 > 13.in
./gen 8000 800000 > 14.in
./gen 10000 1000000 > 15.in
echo "input done"
i=1
while [ "$i" -le 15 ]; do
	./ans < "$i.in" > "$i.out"
	echo "$i output done"
	i=`expr $i + 1`
done
mv *.in res/testdata
mv *.out res/testdata
