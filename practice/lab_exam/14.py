input_str = input("Enter a string: ")
input_str = input_str.lower()
total_sum = 0

for char in input_str:
    if 'a' <= char <= 'z':
        c = ord(char) - ord('a') + 1
        total_sum += c
        print(f"'{char}' ({c}) + ", end='')
print(total_sum)
