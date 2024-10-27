class A:
    def display(self):
        print("from base")
class B(A):
    pass

a=A()
a.display()

b=B()
b.display()
