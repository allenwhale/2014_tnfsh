#!/bin/sh
i=1;
while [ "$i" -le 20 ]; do
	./ans < "$i.in" > "$i.out"
	i=`expr $i + 1`
done
