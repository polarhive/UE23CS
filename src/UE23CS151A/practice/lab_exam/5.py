n = int(input("enter the size of sq matrix: "))
mat = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(int(input("Enter the value for row {} and column {}: ".format(i+1, j+1))))
    mat.append(row)

dsum1, dsum2= 0, 0
for i in range(n):
    dsum1 += mat[i][i]
    dsum2 += mat[i][n-1-i]
print("diagonal sum 1:", dsum1)
print("diagonal sum 2:", dsum2)
