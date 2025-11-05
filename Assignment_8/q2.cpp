#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert a new node
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// (a) Search Recursive
Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchRec(root->left, key);
    } else {
        return searchRec(root->right, key);
    }
}

// (a) Search Iterative
Node* searchItr(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) {
            return root;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

// (b) Minimum element
Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// (c) Maximum element
Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != NULL) {
        return findMin(node->right);
    }
    Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != NULL) {
        return findMax(node->left);
    }
    Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return pred;
}

// Display inorder
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter value to search: ";
    cin >> key;
    Node* r = searchRec(root, key);
    Node* i = searchItr(root, key);
    cout << "Recursive Search: " << (r ? "Found" : "Not Found") << endl;
    cout << "Iterative Search: " << (i ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    int val;
    cout << "Enter node to find successor and predecessor: ";
    cin >> val;
    Node* node = searchRec(root, val);
    if (node) {
        Node* succ = inorderSuccessor(root, node);
        Node* pred = inorderPredecessor(root, node);
        cout << "Inorder Successor: " << (succ ? to_string(succ->data) : "None") << endl;
        cout << "Inorder Predecessor: " << (pred ? to_string(pred->data) : "None") << endl;
    } else {
        cout << "Node not found in BST." << endl;
    }

    return 0;
}
