def is_divisible_by_7(n):
    if n == 0: return True
    elif n < 0: return False
    else:
        return is_divisible_by_7(n - 7)
print(is_divisible_by_7(49))
