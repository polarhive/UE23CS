import csv
lst=[]
fp=open('f.csv', 'r')
csv_file=csv.reader(fp)
for i in csv_file:
    if i[1] >= '2008' and i[1]<='2016':
        lst.append(i[10])
set1=set(lst)
for i in set1:
    print(i,':',lst.count(i))
