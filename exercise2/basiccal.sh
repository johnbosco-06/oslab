#!/bin/bash
a=15; b=5; op="+"

case $op in
    "+") echo "Addition: $((a + b))" ;;
    "-") echo "Subtraction: $((a - b))" ;;
    "*") echo "Multiplication: $((a * b))" ;;
    "/") echo "Division: $((a / b))" ;;
    *) echo "Invalid operator" ;;
esac