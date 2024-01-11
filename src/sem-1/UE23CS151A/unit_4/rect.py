# create a class called rectangle with attr: l and w. Make methods to find area and perimeter. Create object and print area and perimeter
class Rectangle:
    def __init__(self,l,w):
        self.length=1
        self.width=w
    def area(self):
        return self.length*self.width
    def perimeter(self):
        return 2*(self.length+self.width)
r=Rectangle(10,5)
print(r.area())
