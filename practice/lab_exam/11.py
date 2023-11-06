s1 = input("Enter the first string: ")
s2 = input("Enter the second string: ")

if len(s1) != len(s2): print("N")
else:
    concatenated = s2 + s2
    if s1 in concatenated: print("Y")
    else: print("N")
