#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class CircularQueue
{
public:
    Node* front;
    Node* rear;

    CircularQueue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isempty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        Node* newNode = new Node(data);
        if (isempty())
        {
            front = rear = newNode;
            rear->next = front;
        }
        else if (front == rear)
        {
            rear = newNode;
            front->next = rear;
            rear->next = front;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "nothing to delete" << endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
    }

    int peek()
    {
        if (isempty())
        {
            cout << "Empty\n";
            return INT_MIN;
        }
        return front->data;
    }
};

int main()
{
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.isempty() << endl;
    return 0;
}