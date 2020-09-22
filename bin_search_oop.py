from math import floor, ceil

class Search:
    """Search for a value in a sorted array, return the index if found, 
    otherwise return -1"""
    def __init__(self, arr, target):
        self.arr = list(arr)
        self.target = target # Target value
        self.n = len(self.arr) # List length
    
    # Binary search:
    def bin_search(self):
        l = 0
        r = self.n - 1
        while l <= r:
            m = int(floor((l + r) / 2))
            if self.arr[m] < self.target: l = m + 1
            elif self.arr[m] > self.target: r = m - 1
            else: return m
        raise ValueError("Target value not found!")
    
    # Alternate method for binary search:
    def bin_search_alt(self):
        l = 0
        r = self.n - 1
        while l != r:
            m = int(ceil(l + r) / 2)
            if self.arr[m] < self.target: r = m - 1
            else: l = m
            if self.arr[l] == self.target: return l
        raise ValueError("Target value not found!")

    # For duplicate elements:

    # Check if duplicate element exists:
    def is_duplicate(self):
        if len(self.arr) == len(set(self.arr)):
            return "No duplicates."
        else: 
            return "Duplicate found."

    # Method to get the leftmost element index:
    def leftmost(self):
        l = 0
        r = self.n
        while l < r:
            m = int(floor((l + r) / 2))
            if self.arr[m] < self.target: l = m + 1
            else: r = m
        return l

    # Method to get the rightmost element index:
    def rightmost(self):
        l = 0
        r = self.n
        while l < r:
            m = int(floor((l + r) / 2))
            if self.arr[m] > self.target: r = m
            else: l = m + 1
        return r - 1

a = Search([1, 3, 5, 7, 9, 11, 13, 15], 11)
print(a.bin_search())

b = Search([1, 2, 2, 6, 8, 8, 13], 8)
print(b.bin_search())
print(b.is_duplicate())
print(b.leftmost())
print(b.rightmost())