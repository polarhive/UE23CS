"""
Write a python program that takes the file name from the user and reads
the contents(lines) of the file in the reverse order (from bottom). 

File1.txt contents: 
The laughter filled the room, infectious and joyous. 
It echoed and echoed, spreading happiness all around. 
It danced on the airwaves, filling hearts with warmth and light. 

Sample output: Enter file name: File1.txt 
It danced on the airwaves, filling hearts with warmth and light. 
It echoed and echoed, spreading happiness all around. 
The laughter filled the room, infectious and joyous.
"""

file_name=input("Enter file name")
with open(file_name, 'r') as file:
    lines = file.readlines()
reversed_lines = reversed(lines)
for line in reversed_lines: print(line.strip())

