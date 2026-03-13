#!/bin/bash
str="madam"
rev=$(echo $str | rev)

if [ "$str" == "$rev" ]; then
    echo "$str is a Palindrome"
else
    echo "$str is Not a Palindrome"
fi