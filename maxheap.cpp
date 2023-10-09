#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int N = 0;
int arr[MAX_SIZE];

void heapify(int arr[], int n, int pos) {
    int largest = pos; // index of the largest node
    int left = 2 * pos + 1, right = 2 * pos + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != pos) {
        swap(arr[pos], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insertNode(int arr[], int newVal) {
    if (N == MAX_SIZE) {
        cout << "Heap is full. Cannot insert more elements." << endl;
        return;
    }
    arr[N++] = newVal;
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }
}

void deleteRoot(int arr[]) {
    if (N == 0) {
        cout << "Heap is empty. Cannot delete root." << endl;
        return;
    }
    swap(arr[0], arr[N - 1]);
    N--;
    heapify(arr, N, 0);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    insertNode(arr, 10);
    insertNode(arr, 20);
    insertNode(arr, -30);
    insertNode(arr, 9);
    insertNode(arr, 7);
    insertNode(arr, 50);
    cout << "Heap: ";
    display(arr, N);
    deleteRoot(arr);
    cout << "Heap: ";
    display(arr, N);
    return 0;
}
