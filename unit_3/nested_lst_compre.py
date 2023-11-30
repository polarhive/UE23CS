m=[[1,2,3], [4,5,6], [5,6,7]]
newlist=[[r[i] for r in m] for i in range(len(m))]
print(newlist)
