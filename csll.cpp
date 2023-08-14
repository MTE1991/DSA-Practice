#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* tail = nullptr;
int length = 0;

// initialize list (add node to empty list)
void initList(int data) {
    if (!tail) {
        Node* newNode = new Node;
        newNode->data = data;
        tail = newNode;
        tail->next = tail;

        length++;
    } else {
        cout << "List is not empty!\n";
    }
}

// insert at front (for non-empty)
void insertAtFront(int data) {
    if (tail) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = tail->next;
        tail->next = newNode;

        length++;
    } else {
        initList(data);
    }
}

// insert at end
void insertAtEnd(int data) {
    if (tail) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;

        length++;
    } else {
        initList(data);
    }
}

// insert at position
void insertAt(int data, int pos) {
    if (!tail or pos <= 0) {
        cout << "List is empty or invalid position!\n";
        return;
    }
    if (pos == 1) {
        insertAtFront(data);
        return;
    }
    if (pos == length) {
        insertAtEnd(data);
        return;
    }
    if (pos > length) {
        cout << "Out of list range!\n";
    }
    Node* newNode = new Node;
    newNode->data = data;
    Node *curr = tail->next;
    for (int i = 0; i < pos - 2; i++) {
        curr = curr->next;
    }
    if (curr == tail) {
        insertAtEnd(data);
        return;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    length++;
}

// traverse/print the list
void printList() {
    Node* curr = tail->next;
    while (curr != tail) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << curr->data << endl;
}

// count the length of list
int countLen(Node *tail) {
    int count = 0;
    if (!tail) {
        return count;
    }
    Node* curr = tail->next;
    while (curr != tail) {
        curr = curr->next;
        count++;
    }
    count++;
    return count;
}

// delete first node
void deleteFirst() {
    if (!tail) {
        cout << "List is already empty!\n";
        return;
    }
    Node* head = tail->next;
    if (head == tail) {
        delete tail;
        tail = nullptr;
    } else {
        tail->next = head->next;
        delete head;
    }

    length--;
}

// delete node at a specific pos
void deleteAtPosition(int position) {
    if (tail == nullptr or position < 0) {
        cout << "List empty or invalid position!\n";
        return;
    }
    if (position == 1) {
        deleteFirst();
        return;
    }
    if (position > length) {
        cout << "Invalid position!\n";
        return;
    }
    Node* current = tail->next;
    Node* prev = tail;
    int currPos = 0;
    while (currPos < position and current != tail) {
        prev = current;
        current = current->next;
        currPos++;
    }
    prev->next = current->next;
    if (current == tail) {
        tail = prev;
    }
    delete current;

    length--;
}

int main() {
    cout << "length = " << length << endl;
    initList(52);
    printList();
    cout << "length = " << length << endl;
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    printList();
    cout << "length = " << length << endl;
    insertAt(12, 3);
    printList();
    cout << "length = " << length << endl;
    //cout << "No. of nodes = " << countLen(tail) << endl;
    deleteFirst();
    printList();
    cout << "length = " << length << endl;
    //cout << "No. of nodes = " << countLen(tail) << endl;
    deleteAtPosition(4);
    printList();
    cout << "length = " << length << endl;
    //cout << "No. of nodes = " << countLen(tail) << endl;

    return 0;
}
