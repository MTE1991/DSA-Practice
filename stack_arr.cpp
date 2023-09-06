// stack implemented w/ array

#include <iostream>
using namespace std;

const int SIZE = 100;
int arr[SIZE];
int top = -1; // top of stack


bool isFull() {
	return top == SIZE - 1;
}

bool isEmpty() {
	return top == -1;
}

void push(int val) {
	if (isFull()) {
		cout << "Overflow!\n";
	} else {
		arr[++top] = val;
	}
}

int pop() {
	if (isEmpty()) {
		cout << "Underflow!\n";
		return top;
	} else {
		return arr[top--];
	}
}

int peek() {
	if (isEmpty()) {
		cout << "\nStack is empty!";
		return -1;
	}
	return arr[top];
}

void display() {
	if (isEmpty()) {
		cout << "\nStack is empty!";
	} else {
		cout << "Stack: ";
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}

int main() {
	if (isEmpty()) {
		cout << "Stack is empty!\n";
	}
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	display();
	cout << "Popping " << pop() << endl;
	display();
	cout << "Pushing 12\n";
	push(12);
	cout << "Peek() = " << peek() << endl;
	display();

	return 0;
}