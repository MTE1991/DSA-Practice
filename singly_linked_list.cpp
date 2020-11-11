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

    /* Given a reference (pointer to pointer)  
    to the head of a list and an int,  
    inserts a new node on the front of the list. */
    void push(Node **head_ref, int new_data) {  
        /* 1. allocate node */
        Node* new_node = new Node();  
        /* 2. put in the data */
        new_node->data = new_data;  
        /* 3. Make next of new node as head */
        new_node->next = (*head_ref);  
        /* 4. move the head to point to the new node */
        (*head_ref) = new_node;  
    }  

    // Given a node prev_node, insert a  
    // new node after the given   
    // prev_node 
    void insertAfter(Node *prev_node, int new_data) { 
        // 1. Check if the given prev_node is NULL  
        if (prev_node == NULL) {   
            cout << "the given previous node cannot be NULL\n";   
            return;   
        }  
        // 2. Allocate new node 
        Node *new_node = new Node();  
        // 3. Put in the data  
        new_node->data = new_data;   
        // 4. Make next of new node as next of prev_node  
        new_node->next = prev_node->next;   
        // 5. move the next of prev_node as new_node  
        prev_node->next = new_node;   
    }

    // Given a reference (pointer to pointer) to the head   
    // of a list and an int, appends a new node at the end  
    void append(Node** head_ref, int new_data) {         
        // 1. allocate node  
        Node *new_node = new Node();  

        Node *last = *head_ref; // Used in step 5
        // 2. Put in the data  
        new_node->data = new_data;   
        // 3. This new node is going to be the last node, so make next of   
        // it as NULL 
        new_node->next = NULL;   
        // 4. If the Linked List is empty,  
        // then make the new node as head  
        if (*head_ref == NULL) {   
            *head_ref = new_node;   
            return;   
        }   
        // 5. Else traverse till the last node  
        while (last->next != NULL)   
            last = last->next;   
        // 6. Change the next of last node  
        last->next = new_node;   
        return;   
    }

    // Given a reference (pointer to pointer) 
    // to the head of a list and a key, deletes 
    // the first occurrence of key in linked list  
    void deleteNode(Node **head_ref, int key) {       
        // Store head node 
        Node *temp = *head_ref; 
        Node *prev = NULL; 
          
        // If head node itself holds 
        // the key to be deleted 
        if (temp != NULL && temp->data == key) { 
            *head_ref = temp->next; // Changed head 
            delete temp;            // free old head 
            return; 
        } 
        // Else Search for the key to be deleted,  
        // keep track of the previous node as we 
        // need to change 'prev->next' */ 
        while (temp != NULL && temp->data != key) { 
            prev = temp; 
            temp = temp->next; 
        } 
        // If key was not present in linked list 
        if (temp == NULL) 
            return; 
        // Unlink the node from linked list 
        prev->next = temp->next; 
        // Free memory 
        delete temp; 
    } 
}; 

int main() 
{ 
    /* Original list */
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
    cout << "Original list: " << endl;
    head->printList(head);
    cout << endl;

    /* Insert data after a given node */
    head->insertAfter(third->next, 20);
    cout << "Add 20 after 4: " << endl;
    head->printList(head);
    cout << endl;

    /* Append some nodes */
    head->append(&head, 13);
    head->append(&head, 7);
    cout << "After appending some nodes (13, 7): " << endl;
    head->printList(head);
    cout << endl;

    /* Delete some nodes */
    head->deleteNode(&head, 5);
    head->deleteNode(&head, 4);
    cout << "After deletion of some nodes (5, 4): " << endl;
    head->printList(head);
    cout << endl;

    return 0; 
} 