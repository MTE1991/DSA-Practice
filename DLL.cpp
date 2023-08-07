#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node *head = nullptr;

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertAtHead(int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAt(int data, int pos) {
    if (pos <= 1) {
        cout << "Invalid position.\n";
        return;
    }
    if (pos == 1) {
        insertAtHead(data);
        return;
    }
    Node *newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* curr = head;
    for (int i = 0; i < pos - 2; i++) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next = newNode;
    newNode->next->prev = newNode;
}

void insertAtEnd(int data) {
    if (!head) {
        insertAtHead(data);
    } else {
        Node* newNode = createNode(data);
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = nullptr;
    }
}

void deleteAtFront() {
    if (!head) {
        cout << "Cannot remove from empty list.\n";
        return;
    }
    Node* curr = head;
    head = head->next;
    head->prev = nullptr;
    delete curr;
}

void deleteAt(int pos) {
    if (pos <= 1) {
        cout << "Invalid position.\n";
        return;
    }
    if (pos == 1) {
        deleteAtFront();
        return;
    }
    if (!head) {
        cout << "Cannot delete from empty list.\n";
        return;
    }
    Node* curr = head;
    for (int i = 0; i < pos - 2; i++) {
        curr = curr->next;
    }
    if (curr->prev) {
        curr->prev->next = curr->next;
    }
    if (curr->next) {
        curr->next->prev = curr->prev;
    }
    delete curr;
}

void deleteLast() {
    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    Node* last = curr;
    curr->prev->next = nullptr;
    delete last, curr;
}

void printList() {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    cout << "Ekleel\n";

    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtHead(4);
    printList();

    insertAt(5, 2);
    printList();

    insertAtEnd(13);
    printList();

    deleteAtFront();
    printList();

    deleteAt(3);
    printList();

    deleteLast();
    printList();

    return 0;
}