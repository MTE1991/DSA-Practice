# Perform linear search for value "v"
# in array "a".

def linearSearch(a, v):
    i = 0
    
    # if value is found in array, return index
    # of the value, otherwise return 0:
    while i <= len(a):
        if a[i] == val:
            return i
            break
        i += 1
        else: return 0

arr = [5, 2, 4, 6, 1, 3]
value = 6
print(linearSearch(arr, value))
