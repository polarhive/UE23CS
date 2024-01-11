text=input("Enter data in the format: srn, name, age, m1, m2, m3, m4, m5")
d=text.split(',')

srn=input("Enter SRN: ")
name=input("Enter name: ")
age=input("Enter age: ")

m1=input("m1: ")
m2=input("m2: ")
m3=input("m3: ")
m4=input("m4: ")
m5=input("m5: ")

d=dict()
d[srn]=srn
d[name]=name
d[age]=age
d[m1]=m1
d[m2]=m2
d[m3]=m3
d[m4]=m4
d[m5]=m5
print(d)
