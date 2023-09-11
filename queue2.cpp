#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

int Queue[SIZE];
int front = -1, rear = -1;

bool isFull() {
    if ((front == 0 && rear == SIZE - 1) or (front == rear + 1)) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if (front == -1) {
        return true;
    } else {
        return false;
    }
}

void enQueue(int val) {
    if (isFull()) {
        cout << "\nQueue is full!\n";
    } else {
        if (front == -1) {
            front++;
        }
        rear = (rear + 1) % SIZE;
        Queue[rear] = val;
    }
}

int deQueue() {
    if (isEmpty()) {
        cout << "\nQueue is empty!\n";
        return -1;
    } else {
        int removedVal = Queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return removedVal;
    }
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front -> ";
    int i;
    for (i = front; i != rear; i = (i + 1) % SIZE) {
        cout << Queue[i] << " ";
    }
    cout << Queue[i] << " ";
    cout << "<- Rear\n";
}

int main() {
    deQueue();
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    displayQueue();
    deQueue();
    displayQueue();

    return 0;
}
