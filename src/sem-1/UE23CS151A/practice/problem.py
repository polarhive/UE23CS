# given an empty list, insert n elements to list
n=int(input("enter number of elements: "))
lst=[]
for i in range(n):
    lst.append(input("enter the vaule: "))
print(lst)

# given a list, create new list containing sqrt of all elements
import math
lst=[10,20,30,50,2]
newlist=[]
for i in lst:
    newlist.append(math.sqrt(i))
print(newlist)

# print the leftmost even number, else display appropriate message
lst=eval(input("enter list of numbers enclosed in sq brackets: "))
even=[]
for i in lst:
    if i%2==0:
        even.append(i)
    else:
        print("There exists no even number in the list (at i'th posn): ")
print(even)
print("The leftmost even number is: ",even[0])

# given list of integers, add the number n to each element of the list
n=int(input("which number to add?: "))
lst=[1,2,3,4]
for i in range(len(lst)):
    lst[i]+=n
print(lst)

# to create a list of all even numbers between 1 and 20, that are not divisible by 4
lst=[]
for i in range(1,21):
    if (i%2==0 and i%4!=0):
        lst.append(i)
print(lst)

# new list which is sorted
lst=[30,20,12,12]
lst.sort()
print(lst)

# create a list of numbers 1 to n except n//2
n=int(input("enter n: "))
low=1
lst=[]
for i in range(low,n):
    if i==(n//2):
        ("skip")
    else:
        lst.append(i)
print(lst)

# diff b/w succesive elements of a list
lst=[1,5,7,8,10]
for i in range(len(lst)-1):
    print(lst[i+1]-lst[i])

# create a list with unique elements
lst=[1,5,2,5,2,41,6]
print(list(set(lst)))
e=[]

for i in lst:
    if i not in e:
        e.append(i)
print(e)

## use set otherwise
lst=[1,5,2,5,2,41,6]
print(list(set(lst)))

# find leftmost element from list, which is greater than given element 
lst=list(eval(input("enter the numbers: ")))
n = int(input("enter a number from the list: "))
for i in lst:
    if i>n:
        print(i)
        break

# fill numbers from n to 1, and then 2 to n
n=int(input("enter n: "))
lst=[]
for i in range(n,0,-1):
    lst.append(i)
for i in range(2,n+1):
    lst.append(i)
print(lst)

# to find sum: 1*2 + 2*3 upto n terms
n=int(input("enter n: "))
display=""
sum=0
for i in range(1,n+1):
    sum+=(i)*(i+1)
    display=display + str(i) + "*" + str(i+1)+ "+"
l=len(display)-1
print(display[0:l]+" = "+str(sum))

# pattern of 
# 1
# 1 3 
# 1 3 5
# 1 3 5 7

# find the sum of even numbers and sum of odd numbers upto n
n=int(input("enter n: "))
so=0
se=0
for i in range (n):
    if i%2==0:
        se+=i
    else:
        so+=i
print("Odd =",so,"Even =",se)

# 3 lists are given, new list should have the remainder of every element divided by 10
l1=list(eval(input("enter list of numbers: ")))
l2=list(eval(input("enter list of numbers: ")))
l3=list(eval(input("enter list of numbers: ")))

length = [len(l1), len(l2), len(l3)]
len1=min(length)
l=[]
for i in range(len1):
    element = [l1[i]%10, l2[i]%10, l3[i]%10]
    l.append(element)
print(l)

