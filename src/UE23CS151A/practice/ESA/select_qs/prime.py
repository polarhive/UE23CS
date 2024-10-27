# function to check if a number is prime
def is_prime(n):
    return n > 1 and all(n % i != 0 for i in range(2, int(n**0.5) + 1))

a = int(input("Enter a number: "))
print(is_prime(a))
