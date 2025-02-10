#include<bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int value){
        this->value=value;
        left=nullptr;
        right=nullptr;
    } 
};
Node* createTree(){
    int value;
    cout<<"Enter node value (-1 for null) ";
    cin>>value;
    if(value==-1) return nullptr;

    Node* newNode=new Node(value);
    cout<<"Enter left child of "<<value<<endl;
    newNode->left=createTree();
    cout<<"Enter Right child of "<<value<<endl;
    newNode->right=createTree();

    return newNode;
}
void preorder(Node* root){
    if(root){
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<" ";
    }
}

int main(){
    cout<<"Create your binary tree: "<<endl;
    Node* root=createTree();

    cout<<"\nPree Order Traversal: ";
    preorder(root);

    cout<<"\nIn-Oreder Traversal: ";
    inorder(root);

    cout<<"\nPost-Order Traversal: ";
    postorder(root);

    return 0;
}