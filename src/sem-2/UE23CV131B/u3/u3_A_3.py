import math

# Q: A/3
Dx = 15 # 15 mm
A = 300 # 300 mm
Iy = 35*1000 # 35*1000 mm4 

Ix=A*Dx**2 # in mm4
J=Ix+Iy # in mm4
K=math.sqrt(J/A)

result = f"K0 = {round(K, 2)} mm"
print(result)