from math import floor, ceil

a = [1, 3, 5, 7, 9, 11, 13, 15]
n_a = len(a)  # no of elements
t_a = 7  # target value

b = [1, 2, 2, 6, 8, 8, 13]
n_b = len(b)
t_b = 8

# Binary Search function:
def binary_search(arr, n, target):
    l = 0
    r = n - 1
    while l <= r:
        m = int(floor((l + r) / 2))
        if arr[m] < target: l = m + 1
        elif arr[m] > target: r = m - 1
        else: return m
    return -1

# Duplicate elements:

# Finding the leftmost element:
def bin_search_left(arr, n, target):
    l = 0
    r = n
    while l < r:
        m = int(floor((l + r) / 2))
        if arr[m] < target: l = m + 1
        else: r = m
    return l

# Finding the rightmost element:
def bin_search_right(arr, n, target):
    l = 0
    r = n
    while l < r:
        m = int(floor((l + r) / 2))
        if arr[m] > target: r = m
        else: l = m + 1
    return r - 1

print(binary_search(a, n_a, t_a))
print(bin_search_right(b, n_b, t_b))
print(bin_search_left(b, n_b, t_b))
