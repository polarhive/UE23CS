# 1. Use all 3 methods to find the number of lines in your text file
# 2. Search for the occurance of a particular word using read() method

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
    print(lst)
    print(len(lst))
