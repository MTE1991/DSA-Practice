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

// Breadth first search:
vector<int> bfs(Node* root) {
    queue<Node*> queue;
    vector<int> values;
    if (root != nullptr) {
        queue.push(root);
    }
    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop();
        values.push_back(current->val);
        if (current->left != nullptr) {
            queue.push(current->left);
        }
        if (current->right != nullptr) {
            queue.push(current->right);
        } 
    }
    return values;
}

/*
// Sum of all nodes (recursive approach)
int tree_sum(Node* root) {
    if (root != nullptr) {
        return root->val + tree_sum(root->left) + tree_sum(root->right);
    }
    return 0;
}
*/

// Tree sum: Breadth first approach
int tree_sum(Node* root) {
    queue<Node*> queue;
    int sum = 0;
    if (root != nullptr) {
        queue.push(root);
    }
    while(!queue.empty()) {
        Node* current = queue.front();
        queue.pop();
        sum += current->val;
        if (current->left) {
            queue.push(current->left);
        }
        if (current->right) {
            queue.push(current->right);
        }
    }
    return sum;
}

/*
// Recursive (depth first) approach
bool tree_includes(Node* root, int target_val) {
    queue<Node*> queue;
    if (root != nullptr) {
        queue.push(root);
    }
    while (!queue.empty()) {
        Node* curr = queue.front();
        queue.pop();
        if (curr->val == target_val) {
            return true;
        }
        if (curr->left) {
            queue.push(curr->left);
        }
        if (curr->right) {
            queue.push(curr->right);
        }
    }
    return false;
}
*/

bool tree_includes(Node* root, int target_val) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == target_val) {
        return true;
    }
    return tree_includes(root->left, target_val) or tree_includes(root->right, target_val);
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

    vector<int> node_values;

    // Depth first search:
    node_values = dfs(&Root);
    cout << "Depth first values: ";
    for (auto val : node_values) {
        cout << val << " "; // 10 5 4 2 3 8 
    }
    cout << endl;
    node_values.clear();

    // Breadth first search:
    node_values = bfs(&Root);
    cout << "Breadth first values: ";
    for (auto val : node_values) {
        cout << val << " "; // 10 5 4 2 3 8 
    }
    cout << endl; 
    node_values.clear();
  
    // Sum of all nodes
    cout << "Sum of tree = " << tree_sum(&Root) << endl;

    // Check if value exists in tree
    int t = 4;
    if (tree_includes(&Root, t)) {
        cout << t << " exists in this tree.\n";
    } else {
        cout << t << " doesn't exist in this tree.\n";
    }
    return 0;
}
