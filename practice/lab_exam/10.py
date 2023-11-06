test_str = input("Enter the test string: ")
sub_str = input("Enter the substring to find: ")
words = test_str.split()

# Initialize a dictionary to store the count of each sub_str
sub_str_counts = {}

# Iterate through the words and count the occurrences of sub_str
for word in words:
    count = word.count(sub_str)
    if count > 0:
        sub_str_counts[word] = count

# Find the word(s) with the maximum count of sub_str
max_count = max(sub_str_counts.values())
most_repeated_substrings = [word for word, count in sub_str_counts.items() if count == max_count]

# If there are multiple words with the same maximum count, join them
result = ' '.join(most_repeated_substrings)

if result:
    print(f"The most repeated substring is: {result}")
else:
    print(f"No occurrences of '{sub_str}' in the test string.")

