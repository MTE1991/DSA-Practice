#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r);

void mergeSort(int A[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(A, l, mid);
		mergeSort(A, mid + 1, r);
		merge(A, l, mid, r);
	}
}

void merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], R[n2];

	for (int i=0; i < n1; i++)
		L[i] = A[p + i];

	for (int i=0; i < n2; i++)
		R[i] = A[q + 1 + i];

	int i = 0, j = 0, k = p;
	while(i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}


int main() {
	int a[] = {12, 34, 1, 6, 5, 2, 7};
	int n = sizeof(a)/sizeof(a[0]);
	mergeSort(a, 0, n-1);
	for (int i=0; i < n; i++) {
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}
