"""
 Write a python program to read a string of 4 characters in lowercase from the
 user. Print every character of a string along with its uppercase letter and
 its ASCII/Unicode.

Sample Output: 
Enter the string of 4 characters in lowercase: abcd
a A 65
b B 66
c C 67
d D 68
"""

s=input("Enter the string of 4 characters in lowercase: ")
if len(s)==4:
    for c in s: 
        print(c,chr(ord(c)-32),int(ord(c)-32))
else: print("lesser than 4 chars")

