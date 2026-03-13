#!/bin/bash
n=11; is_prime=1

for ((i=2; i<=n/2; i++)); do
    if [ $((n % i)) -eq 0 ]; then
        is_prime=0
        break
    fi
done

if [ $is_prime -eq 1 ]; then 
    echo "$n is Prime"
else 
    echo "$n is Not Prime"
fi