#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    SinglyLinkedList() : head(nullptr) {}

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
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
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
    SinglyLinkedList sll;

    // Inserting elements
    sll.insert(10);
    sll.insert(20);
    sll.insert(30);
    sll.insert(40);

    // Displaying the list
    cout << "Linked List: ";
    sll.display();

    return 0;
}
