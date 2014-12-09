#!/bin/sh
rm -rf res/testdata > /dev/null
mkdir -p res/testdata > /dev/null
./gen 5 5 > 1.in
./gen 10 10 > 2.in
./gen 50 50 > 3.in
./gen 100 100 > 4.in
./gen 500 500 > 5.in
./gen 1000 1000 > 6.in
./gen 2000 2000 > 7.in
./gen 5000 5000 > 8.in
./gen 7000 7000 > 9.in
./gen 10000 10000 > 10.in
./gen 15000 15000 > 11.in
./gen 30000 30000 > 12.in
./gen 50000 50000 > 13.in
./gen 75000 75000 > 14.in
./gen 90000 90000 > 15.in
./gen 100000 100000 > 16.in
./gen 100000 100000 > 17.in
./gen 100000 100000 > 18.in
./gen 100000 100000 > 19.in
./gen 100000 100000 > 20.in
echo "input done"
i=1
while [ "$i" -le 20 ]; do
	./ans < "$i.in" > "$i.out"
	echo "$i output done"
	i=`expr $i + 1 `
done
mv *.in res/testdata
mv *.out res/testdata
