"""
Write a function that accepts a string and calculate the number of upper-case
letters and lower case letters in it.
"""

s=input("enter a string")
print("upper: ", len(list(filter(str.isupper, s))))
print("lower: ", len(list(filter(str.islower, s))))

