import csv
fp=open('f.csv', 'w+', newline='')
fields=['srn', 'name', 'age', 'sem']
csvfile=csv.DictWriter(fp,fieldnames=fields)
csvfile.writeheader()
csvfile.writerow({'srn':1234, 'name': "rahul"})
