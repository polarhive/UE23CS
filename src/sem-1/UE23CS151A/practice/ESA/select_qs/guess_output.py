print(list(map((lambda x: x^2),range(5))))
# stdout: [2, 3, 0, 1, 6]

L=[1,-2,-3,4,5]
def fn(x):
    return x<2
m=filter(fn,L)
print(list(m))

# stdout: [1, -2, -3]

