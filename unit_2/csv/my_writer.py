import csv
with open('f.csv', 'w+', newline='') as fp:
    fields = ['srn', 'name', 'age', 'sem']
    csvfile = csv.DictWriter(fp, fieldnames=fields)
    csvfile.writeheader()
    csvfile.writerow({'srn': 1234, 'name': 'Rahul', 'age': 25, 'sem': 2})
