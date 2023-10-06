# accept 10 numbs
# split into odd and even lists:

lst=[1,2,3,4,5,6,7,8,9,10]
even=[]
odd=[]

print("enter 10 numbers")
for item in lst:
    lst[item]=int(input("enter number: "))
for item in lst:
    if ((lst[item])%2==0):
        even.append(lst[item])
    else:
        odd.append(lst[item])
print(odd)
print(even)
