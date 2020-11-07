#include <stdio.h>
 
void swap(int *a, int *b) 
{ 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 

/* This function takes last element as pivot, places the pivot element at its correct
position in sorted array, and places all smaller (smaller than pivot) to left of pivot and
all greater elements to right of pivot */
int partition(int arr[], int p, int r) { 
    int q = arr[r];    // pivot 
    int i = (p - 1);  // Index of smaller element   

    for (int j = p; j <= r - 1; j++) {     
        if (arr[j] <= q) { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[r]); 
    return (i + 1); 
} 

/* QuickSort procedure (tail recursion)
arr[] --> Array to be sorted, 
p  --> Starting index, 
r  --> Ending index */
void quick_sort(int arr[], int p, int r) { 
    while (p < r) { 
        int q = partition(arr, p, r); // partition index
        quick_sort(arr, p, q - 1); 
        p = q + 1;
    } 
} 

int main() 
{ 
    int arr[] = {10, 7, 8, 19, 1, 50, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    quick_sort(arr, 0, n-1); 

    printf("Sorted array: "); 
    for (int i=0; i < n; i++)
        printf("%i ", arr[i]);
    printf("\n");
    return 0; 
} 
