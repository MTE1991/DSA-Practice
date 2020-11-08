import random
import time

# Source: Wikipedia 
def is_sorted(data) -> bool:
    """Determine whether the data is sorted."""
    return all(data[i] <= data[i+1] for i in range(len(data)-1))

def bogosort(data):
    """Shuffle data until sorted."""
    start = time.time() 

    while not is_sorted(data):
        random.shuffle(data)
        
    end = time.time()

    d = end - start # Execution time
    print("Sorted array: ", data)
    print("Execution time: {d:.2e}s".format(d = d))

bogosort([9,15,41,3,7,9,12,14])
