#!/usr/bin/python3
import sys

def find_prime_factors(num):
    factors = []
    if num % 2 == 0:
        factors.append((num//2, 2))
        return factors
    for i in range(3, num, 2):
        if num % i == 0:
            factor = num // i
            factors.append((factor, i))
            break
    return factors

if __name__ == "__main__":
    filename = sys.argv[1]
    with open(filename) as file:
        for line in file:
            if len(line) == 1:
                break
            num = int(line)
            print("{:d}=".format(num), end="")
            factors = find_prime_factors(num)
            if len(factors) == 1:
                factor, prime = factors[0]
                print("{}*{}".format(factor, prime))
            else:
                print("Invalid input")
