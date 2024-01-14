"""
Write a function to mimic filter() - called myfilter(). Test this with the
following. 

i) Given a list of strings, display all words whose length exceeds 6.
"""

def myfilter(condition, iterable):
    return (item for item in iterable if condition(item))

words = ['apple', 'banana', 'orange', 'watermelon', 'kiwi']
print(list(myfilter(lambda word: len(word) > 6, words)))
