n = int(input("enter the size of sq matrix: "))
mat = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(int(input("Enter the value for row {} and column {}: ".format(i+1, j+1))))
    mat.append(row)

min_value = mat[0][0]
min_row, min_col = 0, 0
for i in range(len(mat)):
    for j in range(len(mat[i])):
        if mat[i][j] < min_value:
            min_value = mat[i][j]
            min_row = i
            min_col = j

print(min_value, "at: ", min_row, min_col)
