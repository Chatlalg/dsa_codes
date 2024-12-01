#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularQueue
{
    Node *front;
    Node *rear;
    int length;

public:
    CircularQueue()
    {
        this->front = nullptr;
        this->rear = nullptr;
        length = 0;
    }

    bool empty()
    {
        return rear == nullptr;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (!newNode)
            cout << "Queue overflow" << endl;
        else
        {
            if (empty())
            {
                front = rear = newNode;
                rear->next = front;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
                rear->next = front;
            }
        }
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue empty" << endl;
        }
        else
        {
            int data = front->data;
            if (front == rear)
            {
                delete front;
                front = rear = nullptr;
            }
            else
            {
                Node *temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
            cout << "Dequeued: " << data << endl;
        }
    }

    void display()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != front); // Stop when we loop back to the front
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue q;
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