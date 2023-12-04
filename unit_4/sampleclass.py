class A:
    count=0
    def __init__(self, name, age):
        self.n=name
        self.a=age
        A.count+=1
    def __del__(self):
        A.count-=1
obj=A('ABC', 20)
obj1=A('XYZ', 30)
obj2=A('c', 40)
print(A.count)
del obj1
print(A.count)