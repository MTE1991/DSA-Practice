#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    // Default Constructor for the root node:
    Node(int init_val) {
        val = init_val;
        left = nullptr;
        right = nullptr;
    }
};

/*
// Depth first traversal (iterative)
vector<int> dfs(Node* root) {
    stack<Node*> temp;
    vector<int> res;
    if (root != nullptr) {
        temp.push(root);
    }
    while (!temp.empty()) {
        Node* curr = temp.top();
        temp.pop();
        res.push_back(curr->val);
        if (curr->right) {
            temp.push(curr->right);
        }
        if (curr->left) {
            temp.push(curr->left);
        }
    }
    return res;
}
*/

// Depth first traversal (recursive)
void dfs(Node* root, vector<int> &values) {
    if (root == nullptr) {
        return;
    }
    values.push_back(root->val);
    dfs(root->left, values);
    dfs(root->right, values);
}

vector<int> dfs(Node* root) {
    vector<int> values;
    dfs(root, values);
    return values;
}

int main() {
    /*
    The tree is supposed to look like this:
                10
               /  \
               5   3
              / \   \ 
              4 2    8
    */

    Node Root(10); // root node
    Node a(3);
    Node b(5);
    Node c(2);
    Node d(4);
    Node e(8);

    // make left and right subtrees
    Root.left = &b;
    Root.right = &a;

    b.left = &d;
    b.right = &c;

    a.right = &e;
    vector<int> node_values = dfs(&Root);
    for (auto val : node_values) {
        cout << val << " ";
    }
    cout << endl; // 10 5 4 2 3 8 
    return 0;
}