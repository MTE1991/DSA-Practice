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

int i = -1;

// BST To MinHeap will work only if values in arr are stored inOrder
void BSTToMinHeap(Node* root, vector<int>& arr, int& i) {
    // perform a preorder traversal
    if (!root) {
        return;
    }
    root->val = arr[++i];
    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}

int main() {
    /*
            4
           /  \
          2    6
         / \   /\
        1   3 5  7
    */
    Node* binTree = createNode(4);
    binTree->left = createNode(2);
    binTree->right = createNode(6);
    binTree->left->left = createNode(1);
    binTree->left->right = createNode(3);
    binTree->right->left = createNode(5);
    binTree->right->right = createNode(7);

    // Converting BST to Min Heap
    vector<int> values;
    inOrder(binTree, values);
    for (auto i : values) {
        cout << i << " ";
    }
    cout << endl;
    BSTToMinHeap(binTree, values, i);

    // inorder traversal of new min heap
    vector<int> values1;
    inOrder(binTree, values1);
    cout << "inorder traversal of new min heap: ";
    for (auto i : values1) {
        cout << i << " ";
    }
    cout << endl;
}

