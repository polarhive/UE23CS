"""
form a list of strings made of First and Last characters from a given list of
words if the length of the string is greater is greater or eq to 3

input: i=['CR7','Messi', "Neymar"]
output: ['C7', 'Mi', 'Nr']
"""

words_list = ['CR7', 'Messi', 'Neymar']
result = [word[0] + word[-1] for word in words_list if len(word) >= 3]
print(result)
