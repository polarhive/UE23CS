import os
print(os.listdir())
def getsize(name):
    return(name, os.path.getsize(name))
for i in map(getsize, os.listdir()):
    print(i[0], "---",i[1])


lst=list(map(getsize, os.listdir()))
print(lst)
