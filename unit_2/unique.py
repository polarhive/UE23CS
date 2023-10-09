lst=list(eval(input("enter the list of values")))
u=[]
for i in lst:
    if(i not in u):
        u.append(i)
print(u)
