a=int(input("enter a: "))
b=int(input("enter b: "))
if a>b: g=a
else: g = b

while (True):
    if g%a==0 and g%b==0:
        lcm = g
        break
    g+=1
print(f"lcm: {lcm}")
