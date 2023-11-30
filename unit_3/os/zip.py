l1=[5,6,7]
l2=[1,2,3]
print(list(zip(l1)))
a=map(lambda x: x, range(1,10))
print(list(zip(a,a)))
a=list(map(lambda x:x, range(1,10)))
print(list(zip(a,a)))
