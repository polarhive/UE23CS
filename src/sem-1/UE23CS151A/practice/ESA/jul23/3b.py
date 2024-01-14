"""
Write a recursive function to find the GCD of 2 numbers in python.
"""

def gcd_recursive(a, b):
    if b == 0:
        return a
    else:
        return gcd_recursive(b, a % b)

num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

print(gcd_recursive(num1, num2))
