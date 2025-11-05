#include <iostream>
#include <algorithm>
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

// (a) Insert (No duplicates)
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {
        root->right = insert(root->right, val);
    } 
    else {
        cout << "Duplicate value " << val << " not allowed." << endl;
    }
    return root;
}

// Find minimum node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// (b) Delete a node
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } 
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// (c) Maximum Depth
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

// (d) Minimum Depth
int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Display (Inorder)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Enter element to delete: ";
    int delVal;
    cin >> delVal;
    root = deleteNode(root, delVal);

    cout << "After deletion (Inorder): ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
