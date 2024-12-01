#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool empty() {
        return rear == nullptr;
    }

    void enqueue(int data) {
        try {
            Node* newNode = new Node(data);
            if (empty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        } catch (std::bad_alloc& e) {
            cout << "Queue full: memory allocation failed." << endl;
        }
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            int data = front->data;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr; // Reset rear when queue becomes empty
            }
            cout << "Dequeued: " << data << endl;
        }
    }

    void display() {
        if (empty()) {
            cout << "Queue empty" << endl;
        } else {
            Node* temp = front;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Queue empty
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    return 0;
}
