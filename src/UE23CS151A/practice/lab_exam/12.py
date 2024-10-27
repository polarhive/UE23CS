s=input("enter string: ")
l=[]
for i in range(len(s)):
    for j in range(i+1,len(s)+1):
        if s[i:j] not in l:
            l.append(s[i:j])
l.sort()
print(l)
