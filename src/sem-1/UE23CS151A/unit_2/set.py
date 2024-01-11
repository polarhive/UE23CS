set1=set()
set1={1,2,3,4}
set2={0}
set1.add(5)
set1.update({5,6})
print(set1)

# non common elements in both sets
set1.symmetric_difference_update(set2)
set1.difference_update(set2)
