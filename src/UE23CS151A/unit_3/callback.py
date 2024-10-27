# callback using list
a=10; print(id(a))
b=10; print(id(b))
# same data

def compute(add, a, b):
    return (add(a,b))

def add(a,b):
    return(a+b)

print(compute(add,10,20))
