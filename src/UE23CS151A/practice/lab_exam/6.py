n = int(input("enter the size of sq matrix: "))
mat = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(int(input("Enter the value for row {} and column {}: ".format(i+1, j+1))))
    mat.append(row)

max_value = mat[0][0]
max_row, max_col = 0, 0
for i in range(len(mat)):
    for j in range(len(mat[i])):
        if mat[i][j] > max_value:
            max_value = mat[i][j]
            max_row = i
            max_col = j

print(max_value, "at: ", max_row, max_col)
