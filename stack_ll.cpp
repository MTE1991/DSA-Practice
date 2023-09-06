// stack implemented w/ singly linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = nullptr; // top of stack

bool isEmpty()
{
    return top == nullptr;
}

bool isFull(Node *curr)
{
    return curr == nullptr;
}

void push(int val)
{
    Node *newNode = new Node;
    if (!isFull(newNode))
    {
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
    else
    {
        cout << "Heap overflow!\n";
    }
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty!\n";
        return -1;
    }

    int poppedValue = top->data;
    Node *temp = top;
    top = temp->next;
    delete temp; // free(temp)
    return poppedValue;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty!\n";
        return -1;
    }
    return top->data;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!\n";
        return;
    }

    cout << "Stack: ";
    Node *curr = top;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    if (isEmpty())
    {
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
