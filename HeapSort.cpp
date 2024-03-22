#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) { // lg n
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n and arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n and arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int n) { // n , n lg n
    // heap build
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int a[] = {30, 40, 35, 50, 90, 34};
    int n = sizeof(a) / sizeof(a[0]);
    heapSort(a, n);

    for (auto i : a) {
        cout << i << endl;
    }
}

/*
         50
        /  \
       40   35
       /\   /
      30 34 
*/