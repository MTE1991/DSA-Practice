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

void deleteBack() {
    Node *end = head;
    Node *prev = NULL;
    while(end->next)
    {
        prev = end;
        end = end->next;
    }
    prev->next = NULL;
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

void deleteNode(int pos) {
    Node *temp = head;
    Node *prev = head;
    if (pos == 1) {
        head = head->next;
        delete temp;
        return;
    }
    for (int i = 0; i < pos; i++) {
        if (i == pos - 1 and temp) {
            prev->next = temp->next;
            delete temp;
        } else {
            prev = temp;
            if (prev == NULL) {
                break;
            }
            temp = temp->next;
        }
    }
}



int main() {
    Node *a = new Node;
    Node *b = new Node;
    Node *c = new Node;
    head = a;

    a->data = 3;
    a->next = b;
    b->data = 5;
    b->next = c;
    c->data = 7;
    c->next = nullptr;

    printList();

    insertFirst(8);
    insertFirst(12);

    printList();

    insertAt(3, 21);

    printList();

    insertAtEnd(52);

    printList();

    deleteFront();

    printList();

    deleteBack();

    printList();

    deleteNode(4);

    printList();

    reverseList();

    printList();

    return 0;
}
