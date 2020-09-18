a = [1, 3, 5, 7, 9, 11, 13, 15]
n = len(a)  # no of elements
t = 7  # target value

# Binary Search function:
def binary_search(arr, n, target):
	l = 0
	r = n - 1
	while l <= r:
		m = (l + r) // 2  # floor value of m
		if arr[m] < target: l = m + 1
		elif arr[m] > target: r = m - 1
		else: return m
	else: return "unsuccessful"

print(binary_search(a, n, t))
