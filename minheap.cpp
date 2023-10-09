#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int N = 0;
int arr[MAX_SIZE];

void heapify(int arr[], int n, int pos) {
    int smallest = pos; // index of the smallest node
    int left = 2 * pos + 1, right = 2 * pos + 2;
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != pos) {
        swap(arr[pos], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void insertNode(int arr[], int newVal) {
    if (N == MAX_SIZE) {
        cout << "Heap is full. Cannot insert more elements." << endl;
        return;
    }
    int i = N;
    arr[i] = newVal;
    N++;
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
    cout << "Min Heap: ";
    display(arr, N);
    
    deleteRoot(arr);
    
    cout << "Min Heap after deleting root: ";
    display(arr, N);
    
    return 0;
}
