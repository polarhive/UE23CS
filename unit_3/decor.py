# decorator
def dec(func):
    def inner():
        print("******")
        func()
        print("******")
    return inner

@dec
def normal():
    print("python")

f=dec(normal)
f()

normal()
