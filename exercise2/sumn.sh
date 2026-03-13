#!/bin/bash
n=10; sum=0

for ((i=1; i<=n; i++)); do
    sum=$((sum + i))
done

echo "Sum of first $n numbers is $sum"