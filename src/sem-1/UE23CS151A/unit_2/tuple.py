# tuple: immutable ordered collection of def 
# index, count, lenof, slicing, del

# tuple type
t=()
print(type(t))

# int type
t=(1)
print(type(t))

# hybrid data types
t1=(1,2,3,6,8,9)
t2=(1,2,4.5,True,"hello")

# tuple expects a ,
tup1=(1,)

# sorting won't work; so use these:
sorted(tup1)
reversed(tup1)

# conversion
lst=list(tup1)
tup2=tuple(lst)
