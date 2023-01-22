/* From chatGPT */

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insert(int data, int pos) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;

        if (pos == 1) {
            temp->next = head;
            head = temp;
            return;
        }

        Node* temp2 = head;
        for (int i = 0; i < pos - 2; i++) {
            temp2 = temp2->next;
        }

        temp->next = temp2->next;
        temp2->next = temp;
    }

    void remove(int pos) {
        Node* temp = head;
        if (pos == 1) {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
        }

        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }

    void search(int data) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == data) {
                std::cout << "Element found at position: " << pos << std::endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        std::cout << "Element not found." << std::endl;
    }

    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList ll;
    ll.insert(5, 1);
    ll.insert(12, 2);
    ll.insert(8, 3);
    ll.insert(15, 4);
    ll.traverse();
    return 0;
}