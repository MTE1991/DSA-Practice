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

void reverseInOrder(Node* root, vector<int>& values) {
    if (!root) {
        return;
    }
    reverseInOrder(root->right, values); // Right subtree first
    values.push_back(root->val);
    reverseInOrder(root->left, values); // Left subtree next
}

void maxHeapify(Node* root, const vector<int>& values, int& i) {
    if (!root) {
        return;
    }
    root->val = values[++i];
    maxHeapify(root->left, values, i);
    maxHeapify(root->right, values, i);
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

    vector<int> values;
    reverseInOrder(binTree, values);

    int i = -1;
    maxHeapify(binTree, values, i);

    vector<int> values1;
    reverseInOrder(binTree, values1);
    cout << "In-order traversal of new max heap: ";
    for (auto i : values1) {
        cout << i << " ";
    }
    cout << endl;
}
