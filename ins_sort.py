# Insertion sort:

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        # Move elements of arr[0..i-1], that are greater than key
        # to one position ahead of their current position
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

a = [21, 12, 3, 8, 5, 18]
print("An unsorted array: ", a)
insertion_sort(a)
print("The sorted array is: ", a)
