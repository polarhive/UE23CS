lst=eval(input("enter numbers: "))
lst1=[str(i)+": even" if i%2==0 else str(i)+": odd" for i in lst ]
print(lst1)
