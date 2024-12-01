// insertion, deletion, and display


#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node in the binary tree
void insert(Node*& root, int value) {
    Node* newNode = new Node(value);
    if (!root) { // If the tree is empty
        root = newNode;
        return;
    }

    // Create a queue for level-order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Check for left child
        if (!temp->left) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        // Check for right child
        if (!temp->right) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Helper function to display the binary tree (Level-Order Traversal)
void levelOrderTraversal(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// Function to delete the deepest node
void deleteDeepest(Node* root, Node* deepestNode) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (temp->left == deepestNode) {
                temp->left = nullptr;
                delete deepestNode;
                return;
            } else {
                q.push(temp->left);
            }
        }

        if (temp->right) {
            if (temp->right == deepestNode) {
                temp->right = nullptr;
                delete deepestNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}

// Function to delete a node with a given key
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr; // If tree is empty

    if (!root->left && !root->right) {
        if (root->data == key) return nullptr; // If tree has one node
        else return root;
    }

    Node* keyNode = nullptr;  // Node to be deleted
    Node* temp;               // Temporary node for traversal
    Node* deepestNode;        // Deepest node in the tree
    queue<Node*> q;
    q.push(root);

    // Perform level-order traversal to find keyNode and deepestNode
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        // finds the required node to be deleted
        if (temp->data == key) {
            keyNode = temp;
        }

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }

        deepestNode = temp; // Last node visited is the deepest node
    }

    // if required key found in the tree
    if (keyNode) {
        // Replace keyNode's value with deepestNode's value
        keyNode->data = deepestNode->data;

        // Delete the deepest node
        deleteDeepest(root, deepestNode);
    }

    return root;
}

int main() {
    Node* root = nullptr;

    // Insert elements into the binary tree
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    // Display the binary tree
    cout << "Level-Order Traversal of Binary Tree: ";
    levelOrderTraversal(root);

    root = deleteNode(root, 20);

    cout << "After Deletion of 20: ";
    levelOrderTraversal(root);

    return 0;
}

// int main() {

// }
