class MyException(Exception):
    def __init__(self,msg):
        print(msg)
a=10
b=0
#b=int(input("enter a value: "))
try:
    if b>10: raise MyException("b is greater than 10")
    else: print(a/b)
except MyException as e: print(e)
