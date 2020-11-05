def shell_sort(arr):
    n = len(arr)
    # Rearrange elements at each n/2, n/4, n/8, ... intervals
    k = n//2
    while k > 0:
        for i in range(k, n):
            temp = arr[i]
            j = i
            while j >= k and arr[j - k] > temp:
                arr[j] = arr[j - k]
                j -= k
            arr[j] = temp
        k //= 2

a = [76, 54, 12, 9, 45, 32, 12, 8, 7, 15]
shell_sort(a)
print(a)
