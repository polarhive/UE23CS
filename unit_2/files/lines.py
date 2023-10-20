# 1. Use all 3 methods to find the number of lines in your text file

with open('text.txt', 'r') as fp:
    print(len(fp.readlines()))

with open('text.txt', 'r') as fp:
    c=0
    while fp.readline():
            c=c+1
    print(c)

with open('text.txt', 'r') as fp:
    str=fp.read()
    lst=str.split('\n')
    print(len(lst)-1)
