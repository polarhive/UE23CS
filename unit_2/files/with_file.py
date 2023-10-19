with open("sample.txt", 'a+') as fp:
    fp.write("entry\n")
    fp.seek(0,0)
    a=fp.read()
    print(a)

# automatically the file will be closed outside `with`
# a=fp.read()
# print(a)
# ^^ these won't work
