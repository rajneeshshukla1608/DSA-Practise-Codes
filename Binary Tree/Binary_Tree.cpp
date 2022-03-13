#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* build(){
    //return the head of the binary tree
    int d;
    cin>>d;
    if(d == -1) return NULL;
    node* root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}

void preorder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);j€j€€€€€€
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL) return;
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

void inorder(node* root){
    if(root == NULL) return;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}


int main(){
    node *root = build();
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    inorder(root);
    return 0;
}
// 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 9 -1 -1 7 -1 -1
//check with the above example;