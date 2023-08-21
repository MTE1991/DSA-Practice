#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = nullptr;

void printList() {
    Node *curr = head;
    while (curr) {
        cout << curr-> data << " ";
        curr = curr->next;
    }
    cout << endl;
}


void insertFirst(int data) {
    Node *newNode;
    newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAt(int pos, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *prev = head;
    for (int i = 1; i < pos - 1; i++) {
        if (prev) {
            prev = prev->next;
            //cout << " value = " << prev->data << " ";
        }
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void insertAtEnd(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node *last = head;

    if (!head) {
        head = newNode;
        return;
    }

    while (last->next) {
        last = last->next;
    }

    last->next = newNode;
}

void deleteFront() {
    Node *curr = head;
    head = head->next;
    delete curr;
}

void deleteNode(int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1) {
        deleteFront();
        return;
    }

    Node* curr = head;
    for (int i = 0; i < pos - 2; i++) {
        if (curr == nullptr or curr->next == nullptr) {
            // out of bounds
            return;
        }
        curr = curr->next;
    }

    Node* temp = curr->next; // n-th pos
    if (temp == nullptr) {
        // out of bounds
        return;
    }
    
    curr->next = temp->next; // Re-link the list
    delete temp; 
}

void deleteBack() {
    Node *end = head;
    Node *prev = nullptr;
    while (end->next) {
        prev = end;
        end = end->next;
    }
    prev->next = nullptr;
    delete end;
}

void reverseList() {
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


int main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    printList();
    insertAt(4, 42);
    printList();
    deleteBack();
    printList();
    deleteNode(6);
    printList();
    return 0;
}
