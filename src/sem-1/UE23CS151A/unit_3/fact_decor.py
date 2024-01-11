import math

def dec(func):
    def inner(*args):
        print("******")
        func(*args)
        print("******")
    return inner

@dec
def fact(n):
    print(math.factorial(n))
fact(5)

@dec
def sq(n):
    print(n**2)
sq(5)
