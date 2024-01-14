"""
use single liners to achieve the following:
i. check if the sum of elements of a is greater than the sum of elements of b
ii. generate a list of integers complementing each element in the given list
    with respect to 100, if the element in a is 25 the corresponding number should
    be 75.
iii. generate the product of all the elements in a
"""

a=[25,24,56,22]
b=[45,67,54,20]

print(sum(a) > sum(b))

complemented_list = [100 - num for num in a]
print(complemented_list)

# not sure
product_of_a = 1 if not a else eval('*'.join(map(str, a)))
print(product_of_a)
