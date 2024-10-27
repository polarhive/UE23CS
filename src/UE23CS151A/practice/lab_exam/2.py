n = int(input("enter an odd row number n: "))
for i in range(1,n+1):
    spaces = abs(n//2-i+1)
    stars = n-2*spaces
    print(" "*spaces + "*"*stars)
