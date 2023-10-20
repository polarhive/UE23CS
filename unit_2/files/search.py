# Search for the occurance of a particular word using read() method
c=0
q=input("search: ")
with open('search.txt', 'r') as fp:
    s=fp.read().split()
    print(s.count(q))
