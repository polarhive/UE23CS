# fp=open("name.txt", 'x')

fp=open("name.txt", 'r')

# will print out 9 chars
print(fp.read(10))

# it will print the blank line also
print(fp.readline())

print(fp.readlines())

# if you don't want the trailing space
print(fp.readline().strip())

fp.close()
