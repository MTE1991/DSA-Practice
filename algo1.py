def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
    return arr

def insertionSortReverse(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] < key:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
    return arr

a = [9, 6, 4, 12, 3, 5]

def bubbleSort(arr):
    for i in range(len(arr)):
        for j in range(0, len(arr) - i - 1):
            if arr[i] > arr[i + 1]:
                arr[i + 1], arr[i] = arr[i], arr[i + 1]
    return arr

print(insertionSort(a))
print(bubbleSort(a))