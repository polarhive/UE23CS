str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")
str1 = str1.replace(" ", "").lower()
str2 = str2.replace(" ", "").lower()

if sorted(str1) == sorted(str2): print("Y")
else: print("N")
