# before printing the cursor has to be placed at a position
row=5
for i in range(1,row+1):
    for k in range (row-i):
        print(end=" ")
    for j in range (1,i+1):
        print(j,end=' ')
    print()
