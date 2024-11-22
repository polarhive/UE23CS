def compute(func, lst1):
    for fun in func:
        print(fun(lst1))

def add(lst1):
    return lst1[0]+lst1[1]
def mul(lst1):
    return lst1[0]*lst1[1]

lst=[add, mul]
lst1=[10,20]
compute(lst,lst1)
