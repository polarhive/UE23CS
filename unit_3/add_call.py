# encapsulation

def comp(add, x,y):
    print(id(x))
    print(id(y))
    return add(x,y)

def add(a,b):
    print(id(a))
    print(id(b))
    return(a+b)

print(comp(add,5,2))
