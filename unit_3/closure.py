def outer():
    m="hello"
    def inner():
        print("test", m)
    return inner

# inner/outer scope
fun=outer()
fun()

# here it is directly calling the inner method not the outer one
# it is directly returning the addr of the object

del outer
#print(outer())
fun()

