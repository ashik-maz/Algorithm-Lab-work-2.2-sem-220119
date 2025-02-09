#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to create a binary tree dynamically from user input
Node* createTree() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return NULL; // Base case: No node

    Node* newNode = new Node(val);
    cout << "Enter left child of " << val << endl;
    newNode->left = createTree();
    cout << "Enter right child of " << val << endl;
    newNode->right = createTree();

    return newNode;
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    cout << "Create your binary tree:" << endl;
    Node* root = createTree();

    cout << "\nPre-order traversal: ";
    preorder(root);
    
    cout << "\nIn-order traversal: ";
    inorder(root);
    
    cout << "\nPost-order traversal: ";
    postorder(root);
    
    cout << endl;
    return 0;
}
