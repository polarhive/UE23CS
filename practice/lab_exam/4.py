def a(n):
    num_str = str(n)
    num_digits = len(num_str)
    armstrong_sum = sum(int(digit) ** num_digits for digit in num_str)
    return armstrong_sum == n

n=int(input("enter a number: "))
if n > 0: print(a(n))
else: print("enter a +ve integer number")
