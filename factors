#!/usr/bin/python3

import sys

def get_least_prime_factor(n):
    if n % 2 == 0:
        return 2

    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return i
    return n

def factorise_number(n):
    factors = []

    while n > 1:
        least_prime_factor = get_least_prime_factor(n)
        factors.append(least_prime_factor)
        n //= least_prime_factor

    return factors

def main():
    with open(sys.argv[1], 'r') as source:
        num = [int(line.strip()) for line in source if line.strip()]

    for n in num:
        factors = factorise_number(n)
        if factors:
            least_prime_factor = factors[0]
            quotient = n // least_prime_factor
            print("{}={}*{}".format(n, least_prime_factor, quotient))
        else:
            print("{}=1*{}".format(n, n))

if __name__ == "__main__":
    main()

