def remove_f(lst, k):
    element_count = {}
    for element in lst:
        if element in element_count: element_count[element] += 1
        else: element_count[element] = 1
    return [element for element in lst if element_count[element] != k]

n = int(input("Enter the number of elements (n): "))
k = int(input("Enter the desired occurrence frequency (k): "))

# check if k<=n
lst = [int(input(f"Enter element {i+1}: ")) for i in range(n)]

print(remove_f(lst, k))
