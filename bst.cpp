#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

Node* delIterative(Node* root, int key) {
    Node* curr = root;
    Node* prev = NULL;


    // finds node where key exists
    while (curr != NULL && curr->key != key) {
        prev = curr;
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL) 
        return root;

    if (curr->left == NULL || curr->right == NULL) {
        Node* newCurr;

        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;

        if (prev == NULL)
            return newCurr;

        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;

        delete curr;
    } else {
        Node* p = NULL;
        Node* temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }

        if (p != NULL)
            p->left = temp->right;
        else
            curr->right = temp->right;

        curr->key = temp->key;
        
        delete temp;
    }
    return root;
}

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

// A utility function to insert a new node with 
// the given key
Node* insert(Node* node, int key) {
  
    // If the tree is empty, return a new node
    if (node == NULL) 
        return new Node(key);    
    
    // If the key is already present in the tree,
    // return the node
    if (node->key == key) 
        return node;
    
    // Otherwise, recur down the tree/ If the key
    // to be inserted is greater than the node's key,
    // insert it in the right subtree
    if (node->key < key) 
        node->right = insert(node->right, key);
    
    // If the key to be inserted is smaller than 
    // the node's key,insert it in the left subtree
    else 
        node->left = insert(node->left, key);
    
    // Return the (unchanged) node pointer
    return node;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 15;

    root = delIterative(root, x);
    inorder(root);
    return 0;
}
