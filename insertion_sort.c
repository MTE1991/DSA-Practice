#include <stdio.h>

void insertion_sort(int arr[], int n);
void print_arr(int arr[], int n);

int main()
{
	int a[] = {21, 12, 3, 8, 5, 18};
	int n = sizeof(a) / sizeof(a[0]);

	printf("Unsorted:\n");
	print_arr(a, n);
	insertion_sort(a, n);
	printf("Sorted using insertion sort:\n");
	print_arr(a, n);

	return 0;
}

void insertion_sort(int arr[], int n) {
	int i, j, key;

	for (i = 0; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are greater than key
        to one position ahead of their current position: */
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
            j--;
		}
	arr[j + 1] = key;
	}
}

void print_arr(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}
