#include <iostream>
using namespace std;

class Node 
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Queue
{
    private:
    int front;
    int rear;
    int size;
    Node **Q;

    public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this -> size = size;
        Q = new Node *[this->size];
    }
    void enqueue(Node * x);
    Node * dequeue();
    bool isEmpty();
};

void Queue::enqueue(Node * x)
{
    if (rear == size - 1)
        printf("Queue Full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node * Queue::dequeue()
{
    Node * x = NULL;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

bool Queue:: isEmpty()
{
    if(front == rear)
        return true;
    return false;
}