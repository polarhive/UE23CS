class A:
    def display(self):
        print("from base")
class B(A):
    def display(self):
        super().display()
        print("from child")

a=A()
a.display()

b=B()
b.display()
