#!/usr/bin/python3
import sys

def factoriser(num):
    for i in range(2, int(num / 2) + 1):
        if num % i == 0:
            return (num//i, i)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        exit()
    factors = sys.argv[1]
    try:
        with open(factors, 'r') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("File not found")
        exit()
    
    for line in lines:
        num = int(line.strip())
        result = factoriser(num)
        print("{}={}*{}".format(num, result[0], result[1]))
