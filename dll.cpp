#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr) {}

    // Insert at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) { // If the list is empty
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) { // Traverse to the end
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;

        // Find the node with the given value
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        // If node to be deleted is the head
        if (temp == head) {
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
        } else {
            // Update links
            if (temp->prev)
                temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            delete temp;
        }

        cout << "Node with value " << value << " deleted." << endl;
    }

    // Search for a value in the list
    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main Function
int main() {
    DoublyLinkedList dll;

    // Inserting elements
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);

    // Displaying the list
    cout << "Doubly Linked List: ";
    dll.display();

    // Searching for a node
    int searchVal = 20;
    cout << "Searching for " << searchVal << ": "
         << (dll.search(searchVal) ? "Found" : "Not Found") << endl;

    // Deleting a node
    dll.deleteNode(20);
    cout << "After deletion: ";
    dll.display();

    return 0;
}
