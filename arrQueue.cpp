#include <bits/stdc++.h>
using namespace std;
#define MAX 10

class Queue{
    int front=0,rear=-1;
    int queue[MAX];    
public:
    void enqueue(int data){
        if(full()){
            cout<<"Queue full"<<endl;
        }else{
            queue[++rear]=data;
        }
    }
    
    void dequeue(){
        if(empty()){
            cout<<"Queue empty"<<endl;
            front=0,rear=-1;
        }else{
            cout<<queue[front++]<<endl;
            // front++;
        }
    }

    bool empty(){
        return front>rear;
    }

    bool full(){
        return rear==MAX-1;
    }

    int print(){
        // if(empty()){
        //     cout<<"Queue is empty"<<endl;
        //     return;
        // }
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
        return 1;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(40);
    q.enqueue(4130);
    q.enqueue(50);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(44520);
    q.enqueue(4540);
    q.enqueue(4230);
    q.enqueue(44520);
    q.print();
    return 0;
};