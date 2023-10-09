#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int val) {
    if (!root) {
        return createNode(val);
    }
    if (val > root->val) {
        root->right = insertNode(root->right, val);
    } else if (val <= root->val) {
        root->left = insertNode(root->left, val);
    }
    return root;
}

Node* deleteNode(Node* root, int k) {
    if (!root) {
        return root;
    }
    if (root->val > k) {
        root->left = deleteNode(root->left, k);
        return root;
    } else if (root->val < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (!root->left) {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (!root->right) {
        Node* temp = root->left;
        delete root;
        return temp;
    } else {
        Node* nextParent = root;
        Node* next = root->right;
        while (next->left) {
            nextParent = next;
            next = next->left;
        }
        if (nextParent != root) {
            nextParent->left = next->right;
        } else {
            nextParent->right = next->right;
        }
        root->val = next->val;
        delete next;
        return root;
    }
}

void inOrder(Node* root, vector<int>& values) {
    if (!root) {
        return;
    }
    inOrder(root->left, values);
    values.push_back(root->val);
    inOrder(root->right, values);
}

void preOrder(Node* root, vector<int>& values) {
    if (!root) {
        return;
    }
    values.push_back(root->val);
    preOrder(root->left, values);
    preOrder(root->right, values);
}

void postOrder(Node* root, vector<int>& values) {
    if (!root) {
        return;
    }
    postOrder(root->left, values);   
    postOrder(root->right, values);
    values.push_back(root->val);
}

void secondLargest(Node* root) {
    static int count = 0;
    if (!root or count >= 2) {
        return;    
    } 
    secondLargest(root->right);
    count++;
    if (count == 2) {
        cout << "Second largest node = " << root->val << endl;
        return;
    }
    secondLargest(root->left);
}

void secondSmallest(Node* root) {
    static int count = 0;
    if (!root or count >= 2) {
        return;    
    } 
    secondSmallest(root->left);
    count++;
    if (count == 2) {
        cout << "Second smallest node = " << root->val << endl;
        return;
    }
    secondSmallest(root->right);
}

int main() {
    Node* binTree = insertNode(binTree, 32);
    insertNode(binTree, 12);
    insertNode(binTree, 98);
    insertNode(binTree, 52);
    insertNode(binTree, 90);
    insertNode(binTree, 20);
    vector<int> values;
    inOrder(binTree, values);
    for (auto i : values) {
        cout << i << " ";
    }
    cout << endl;
    secondLargest(binTree);
    secondSmallest(binTree);
}

