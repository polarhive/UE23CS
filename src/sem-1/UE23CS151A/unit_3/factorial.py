def factorial(n):
    if n==0: return 1
    else: return n*factorial(n-1)

def fact(n):
    f=1
    if n==0: return f
    else:
        for i in range(1,n+1):
            f=f*i
        return f
print(fact(0))
print(factorial(0))
