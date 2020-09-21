#include <stdio.h>

void print_arr(int arr[], int n);
void swap(int *x, int *y);
void select_sort(int arr[], int n);

int main(void)
{
	int a[] = {5, 2, 12, 6, 3, 7, 9, 11};
	int n = sizeof(a) / sizeof(a[0]);

	printf("Unsorted array: \n");
	print_arr(a, n); 
	select_sort(a, n);
	printf("Sorted using selection sort: \n");
	print_arr(a, n);

	return 0;
}

void print_arr(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}

void swap(int *x, int *y) {
	int temp = *x; 
    *x = *y;
    *y = temp; 
}

void select_sort(int arr[], int n) {
	int i, min;

	for (i = 0; i < n; i++) {
		min = i;

		/* Find the minimum element in remaining
        unsorted array: */
		for (int j = i + 1; j < n; j++) {
			if (arr[min] > arr[j]) min = j;
		}

	/* Swap the found minimum element with
    the first element: */
	swap(&arr[min], &arr[i]);
	}
}