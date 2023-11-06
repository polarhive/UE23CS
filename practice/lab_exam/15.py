s = input()
converted = ""
for char in s:
    if char.isalpha():
        if char == 'z': converted += 'a'
        elif char == 'Z': converted += 'A'
        else: converted += chr(ord(char) + 1)
    else: converted += char
print(converted)
