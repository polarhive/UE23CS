def sub(a,b):
    if b==0: return a
    return sub(a-1,b-1)
print(sub(5,2))
