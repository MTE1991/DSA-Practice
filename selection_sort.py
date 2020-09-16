# Selection sort:

def select_sort(a):
    for i in range(len(a)):
        # Find the minimum element in remaining
        # unsorted array:
        min = i
        for j in range(i+1, len(a)):
            if a[min] > a[j]:
                min = j

        # Swap the found minimum element with
        # the first element:
        a[i], a[min] = a[min], a[i]

a = [21, 12, 3, 8, 5, 18]
print("An unsorted array: ", a)
select_sort(a)
print("The sorted array is: ", a)
