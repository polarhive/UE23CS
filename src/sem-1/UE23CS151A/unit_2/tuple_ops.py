tup1=(1,2,3,6,8,9)

# here it converts the tuple -> list; so we have to convert it back to a tuple again!
print(tuple(sorted(tup1)))
print(tuple(reversed(tup1)))

while(1>0):
    tup1=(tuple(reversed(tup1)))
    print(tup1)
