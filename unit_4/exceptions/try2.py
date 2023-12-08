try:
    a=int(input("enter the number: "))
    b=int(input("enter the number: "))
    c=a/b
except (ZeroDivisionError, ValueError) as e:
    print("Error", e)
else: print(c)
finally: print("after try and except")
