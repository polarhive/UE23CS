try: 
    raise Exception
    a,b=10,0
    c=a/b
except: print("raised")

try: 
    raise ValueError("value error", "test")
except Exception as e: print("raised as: ",e)
