#include <iostream> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node *next;

    // This function prints contents of linked list 
    // starting from the given node 
    void printList(Node *n) { 
        while (n != NULL) { 
            cout << n->data << " "; 
            n = n->next; 
        } 
    } 
}; 

int main() 
{ 
    Node *head = NULL; 
    Node *second = NULL; 
    Node *third = NULL;
    Node *fourth = NULL;
  
    // allocate 4 nodes in the heap 
    head = new Node(); 
    second = new Node(); 
    third = new Node();
    fourth = new Node();
  
    head->data = 3; // assign data in the node 
    head->next = second; // link it to next node

    second->data = 5; 
    second->next = third; 
  
    third->data = 4;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = NULL;
  
    head->printList(head);
  
    return 0; 
} 