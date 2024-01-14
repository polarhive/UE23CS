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

print([100 - num for num in a])

# import isn't a line :/
from functools import reduce
print(reduce(lambda x, y: x * y, a, 1) if a else 1)
