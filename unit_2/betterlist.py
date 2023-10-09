# accept 10 numbs
# order: expression, forloop, condition
lst=list(eval(input("enter the list of values")))
odd=[]
for i in lst:
    if (i%2==1):
        odd.append(i)
print(odd)
