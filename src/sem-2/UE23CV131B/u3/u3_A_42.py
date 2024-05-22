import math

# Q: A/42
Dx = 100 # 100 mm
Dy = 90 # 90 mm
R = 30 # 30 mm

Ix1=1/12*Dx*Dy**3 # in mm4
Ix2=-math.pi/8*R**4 # in mm4
Ix=(Ix1+Ix2) # in mm4 
Ix=Ix/10**6 # in 10^6 mm4 

result = f"Ix = {round(Ix, 2)} x 10^6 mm4"
print(result)