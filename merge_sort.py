def merge_sort(arr):

    if len(arr) > 1:
        # Midpoint to divide the array into two halves:
        m = len(arr) // 2

        l = arr[:m]  # left half
        r = arr[m:]  # right half

        # Recursively divide both halves untill its length
        # becomes 1:
        l = merge_sort(l)
        r = merge_sort(r)

        # Merge the two halves:
        arr = []  # Sorted array

        while len(l) > 0 and len(r) > 0:
            if l[0] > r[0]:
                arr.append(r[0])
                r.pop(0)
            else:
                arr.append(l[0])
                l.pop(0)

        for i in l:
            arr.append(i)
        for i in r:
            arr.append(i)

    return arr

print(merge_sort([38, 27, 43, 3, 9, 82, 10]))
