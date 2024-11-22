# generator function:
# provides a way to create a function that behaves like an iterator
# stores the value into an object

#def gen_name(arg):
#    yield value

# for loop from -- 1 to 100

def genx():
    yield 1
    yield 2
    yield 3
    # the control doesn't come out of the program

for i in genx():
    print(i)

obj=genx()
print(type(genx))
print(next(obj))
print(next(obj))
