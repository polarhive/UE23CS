import string

original_strings = ['hello', 'world!', 'python?', 'list', 'comprehension!']
filtered_strings = [s for s in original_strings if all(char not in string.punctuation for char in s)]

# all: return true if all the iterables return true
print(filtered_strings)

