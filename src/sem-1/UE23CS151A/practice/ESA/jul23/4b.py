""" Given the below mentioned list. Write a python code using lambda
list1 = [ 'Java', 'Python', 'Csharp', 'Javascript', 'Go', 'Swift' ]

i) To convert the strings to lowercase if the length of it less than 4 and display it.
ii) Display all the strings in the list which has the letter 'o' in it.
"""

list1 = ['Java', 'Python', 'Csharp', 'Javascript', 'Go', 'Swift']

print(list(map(lambda x: x.lower() if len(x) < 3 else x, list1)))
print(list(filter(lambda x: 'o' in x, list1)))
