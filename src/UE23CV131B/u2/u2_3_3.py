import math

# Q: 3/3
g = 9.81
w = 6 # in kg
d1 = 0.9 # in m
d2 = 0.6 # in m

# Taking ACW as [+ve] and equating ΣM = 0
Na = w*g*d1 / d2 

result = f"Na = {round(Na, 1)} N"
print(result)
