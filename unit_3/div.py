def div(a,b):
    if a<=0 or b==0: return 0
    return (1+div(a-b,b))
print(div(22,2))

