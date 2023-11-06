def keep_k(lst, k):
    element_count = {}
    result = []
    for element in lst:
        if element in element_count:
            element_count[element] += 1
        else:
            element_count[element] = 1
        if element_count[element] == k:
            result.append(element)
    return result

n = int(input("Enter the number of elements (n): "))
k = int(input("Enter the desired occurrence frequency (k): "))

lst = [int(input(f"Enter element {i+1}: ")) for i in range(n)]
print(keep_k(lst, k))
