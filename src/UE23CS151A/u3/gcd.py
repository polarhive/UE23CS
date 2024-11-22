def gcd(m,n):
    if m==n: return m
    elif m>n: return gcd(m-n,n)
    else: return gcd(m,n-m)
print(gcd(91,65))
print(gcd(21,65))
print(gcd(91,32))
