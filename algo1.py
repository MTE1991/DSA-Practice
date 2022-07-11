def insertionSortReverse(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] < key:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
    return arr

def insertionSort(A):
	for i in range(1, len(A)):
		key = A[i]
		j = i - 1
		while j >= 0 and A[j] > key:
			A[j + 1] = A[j]
			j -= 1
		A[j + 1] = key

#def selectionSort(A)

def bubbleSort(A):
	for i in range(0, len(A)-1):
		for j in range(0, len(A)-1):
			if A[j + 1] <= A[j]:
				A[j + 1], A[j] = A[j], A[j + 1]

def mergeSort(A, left, right):
	if left < right:
		mid = (left + right) // 2
		mergeSort(A, left, mid)
		mergeSort(A, mid + 1, right)
		merge(A, left, mid, right)

def merge(A, p, q, r):
	n1 = q - p + 1
	n2 = r - q
	L = [0] * n1
	R = [0] * n2

	for i in range(0, n1):
		L[i] = A[p + i]
	for i in range(0, n2):
		R[i] = A[q + 1 + i]

	i = j = 0
	k = p 

	while i < n1 and j < n2:
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1
		k += 1

	while i < n1:
		A[k] = L[i]
		i += 1
		k += 1
	while j < n2:
		A[k] = R[j]
		j += 1
		k += 1

		
