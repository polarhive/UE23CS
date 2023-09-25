n=int(input("enter number to reverse: "))
# copy the variable here

rem=0
reverse=0
i=0

l=len(str(n))

for i in range(l):
    rem=n%10
    reverse = reverse * 10 + rem
    n=n//10
print(reverse)
