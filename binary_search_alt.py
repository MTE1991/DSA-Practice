from math import floor, ceil

a = [1, 3, 5, 7, 9, 11, 13, 15]
n = len(a)  # no of elements
t = 7  # target value

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

# Alternate function:
def binary_search_alt(arr, n, target):
    l = 0
    r = n - 1
    while l != r:
        m = int(ceil((l + r) / 2))
        if arr[m] < target: r = m - 1
        else: l = m
    	if arr[l] == target: return l
    return -1

print(binary_search_alt(a, n, t))
