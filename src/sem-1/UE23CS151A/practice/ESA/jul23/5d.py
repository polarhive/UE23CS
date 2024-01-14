"""
Create a super class named A and a subclass named B. B class inherits the
properties of the A class. The super class has an attribute called list L,
which is homogeneous and contains integers. List may contain duplicate
elements. Write a program such that the subclass removes the duplicate 
elements from the list (if any).

Sample input: L = [10,20,30,30,20,90,10,80]
Expected output: L = [10,20,30,90,80]
"""

class A:
    def __init__(self, L):
        self.L = L

class B(A):
    def remove_duplicates(self):
        self.L = list(set(self.L))

# sample input
L = [10, 20, 30, 30, 20, 90, 10, 80]

# create an instance of subclass B
obj_B = B(L)
obj_B.remove_duplicates()

print("Original List:", L)
print("List after removing duplicates:", obj_B.L)
