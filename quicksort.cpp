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
int partition(int arr[], int low, int high) { 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element   

    for (int j = low; j <= high- 1; j++) {     
        if (arr[j] <= pivot) { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

  
/* QuickSort procedure
arr[] --> Array to be sorted, 
low  --> Starting index, 
high  --> Ending index */
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high); 

        /* Separately sort elements before 
        partition and after partition */
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 

    } 
} 

int main() 
{ 
    int arr[] = {10, 7, 8, 19, 1, 50, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    quickSort(arr, 0, n-1); 

    printf("Sorted array: "); 
    for (int i=0; i < n; i++)
        printf("%i ", arr[i]);

    return 0; 
} 