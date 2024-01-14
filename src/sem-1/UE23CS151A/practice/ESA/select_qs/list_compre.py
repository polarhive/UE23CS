"""
1. Find all numbers which are odd and which are palindromes bw a pair of number: Say [20, 100] both are inclusive
2. Create a list of numbers and a list of strings. Both the lists are of the same size. Combine the 2 lists to make a list of tuples.
"""

start, end = 20, 100
odd_palindromes = [num for num in range(start, end+1) if num % 2 != 0 and str(num) == str(num)[::-1]]
print(odd_palindromes)

numbers = [1, 2, 3, 4, 5]
strings = ['one', 'two', 'three', 'four', 'five']
print(list(zip(numbers, strings)))
