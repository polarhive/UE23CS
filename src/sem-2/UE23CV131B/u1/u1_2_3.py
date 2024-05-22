import math

# Q: 2/3
F = 6.5 * 1000
y = -5
x = -12

theta = math.atan2(y, x)
Fx = math.cos(theta) * F
Fy = math.sin(theta) * F

result = f"F = {round(Fx / 1000, 1)}i {round(Fy / 1000, 1)}j kN"
print(result)
