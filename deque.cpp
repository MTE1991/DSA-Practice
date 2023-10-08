#include <iostream>
using namespace std;

const int SIZE = 100;
int arr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (rear + 1) % SIZE == front;
}

bool isEmpty() {
    return front == -1;
}

void insertFront(int item) {
    if (isFull()) {
        cout << "Deque is full. Cannot insert at the front." << endl;
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    arr[front] = item;
}

void insertRear(int item) {
    if (isFull()) {
        cout << "Deque is full. Cannot insert at the rear." << endl;
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    arr[rear] = item;
}

int deleteFront() {
    if (isEmpty()) {
        cout << "Deque is empty. Cannot delete from the front." << endl;
        return -1; 
    }
    int deletedItem = arr[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    return deletedItem;
}

int deleteRear() {
    if (isEmpty()) {
        cout << "Deque is empty. Cannot delete from the rear." << endl;
        return -1; 
    }
    int deletedItem = arr[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
    return deletedItem;
}

int getFront() {
    if (isEmpty()) {
        cout << "Deque is empty." << endl;
        return -1; 
    }
    return arr[front];
}

int getRear() {
    if (isEmpty()) {
        cout << "Deque is empty." << endl;
        return -1; 
    }
    return arr[rear];
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front -> ";
    int i;
    for (i = front; i != rear; i = (i + 1) % SIZE) {
        cout << arr[i] << " ";
    }
    cout << arr[i] << " ";
    cout << "<- Rear\n";
}

int main() {
    insertFront(1);
    insertFront(2);
    insertFront(3);
    insertFront(4);
    insertFront(5);
    display();
    
    insertRear(10);
    insertRear(20);
    insertRear(30);
    display();
    
    deleteFront();
    deleteRear();
    display();
    
    cout << "Front = " << getFront() << ", Rear = " << getRear() << endl;
    return 0;
}
