n=int(input("enter number: "))
i=1
odd=""
even=""
while (i<=n):
    if (i%2 == 0):
        even=(even+' '+str(i))
    else:
        odd=(odd+' '+str(i))
    i+=1

print(odd)
print(even)
