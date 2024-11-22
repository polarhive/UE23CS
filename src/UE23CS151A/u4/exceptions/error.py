try: 
    a,b=10,0
    c=a/b
except Exception as e: print("generic: ", e)
except ValueError as e: print("value: ", e)
except ZeroDivisionError as e: print("zero", e)
else: print(c)
