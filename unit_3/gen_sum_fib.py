def fib(n):
    x=0; y=1
    for i in range(n):
        x,y=y,x+y
        yield x

def sq(n):
    for i in n:
        yield i**2
print(sum(sq(fib(5))))
