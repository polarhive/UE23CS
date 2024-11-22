def mul(a,b):
    if b==1: return a
    return a+mul(a,b-1)
print(mul(5,2))
