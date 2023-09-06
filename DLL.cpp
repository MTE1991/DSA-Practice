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
    head = curr->next;
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
    delete curr;
}

void printList() {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void reverseList() {
    Node* curr = head; 
    Node* temp = nullptr;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // Corner cases (empty list, list w/ just 1 node)
    if (temp) {
        head = temp->prev;
    }
}

/*
void twoWayTraverse(Node* curr) {
    char direction;
    cout << "Enter (L) to go left and (R) to go right (Q to quit): ";
    cin >> direction;
    cout << "Starting from: " << curr->data << endl;
    if (toupper(direction) == 'L') {
        curr = curr->prev;
        if (curr) {
            cout << "Data: " << curr->data << endl;
            twoWayTraverse(curr);
        } else {
            cout << "No data at previous position. Returning to head...\n";
            curr = head;
            twoWayTraverse(curr);
        }
    } else if (toupper(direction) == 'R') {
        curr = curr->next;
        if (curr) {
            cout << "Data: " << curr->data << endl;
            twoWayTraverse(curr);
        } else {
            cout << "No data at next position. Returning to head...\n";
            curr = head;
            twoWayTraverse(curr);
        }
    } else {
        cout << "Successfully exited the function.\n";
        return;
    }
}
*/

int main() {
    cout << "Ekleel\n";

    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtHead(4);
    insertAtHead(6);
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
    reverseList();
    printList();
    //twoWayTraverse(head);
    return 0;
}
