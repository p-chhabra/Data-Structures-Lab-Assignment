#include<bits/stdc++.h>
using namespace std;

///IMPLEMENTATION USING ARRAYS
class Queue
{
public:
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    int * arr;

    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
        firstIndex = -1;
        nextIndex = 0;
    }

    void enqueue(int data)
    {
        if(size == capacity)
        {
            cout<<"Queue Full"<<endl;
            return;
        }
        if(firstIndex == -1)
        {
            firstIndex = 0;
            arr[nextIndex] = data;
            nextIndex++;
            size++;
            return;
        }
        arr[nextIndex] = data;
        nextIndex++;
        size++;
    }

    void dequeue()
    {
        if(size == 0)
        {
            cout<<"Queue Empty"<<endl;
            return;
        }
        firstIndex++;
        size--;
    }

    int front()
    {
        if(size == 0)
        {
            cout<<"Queue Empty"<<endl;
            return -1;
        }
        return arr[firstIndex];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    void print()
    {
        for(int i = firstIndex; i < nextIndex; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


///IMPLEMETATION USING LINKED LIST
class Node
{
    public:
    Node * next;
    int data;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class QueueLL
{
    public:
    int size;
    Node * head;
    Node * tail;

    QueueLL()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void enqueue(int data)
    {
        if(!head)
        {
            Node * n = new Node(data);
            head = n;
            tail = n;
            size++;
            return;
        }
        Node * n = new Node(data);
        tail->next = n;
        tail = n;
        size++;
    }

    void dequeue()
    {
        if(!head)
        {
            cout<<"Queue Empty"<<endl;
            return;
        }
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    int front()
    {
        return head->data;
    }
};

int main()
{
    Queue q(5);
    char x;
    while(x != 'e')
    {
    cout<<"Enter 'i' to push an element || Enter 'd' to pop an element || Press 'p' to print Queue ||Enter 'e' to exit"<<endl;
    cin>>x;
    switch(x)
    {
        case 'i':
        {
            int element;
            cout<<"Enter element to be inserted"<<endl;
            cin>>element;
            q.enqueue(element);
            break;
        }

        case 'd':
        {
            q.dequeue();
            break;
        }

        case 'e':
        {
            break;
        }

        case 'p':
            {
                q.print();
                break;
            }

        default:
            {
                cout<<"Wrong Character Entered"<<endl;
                break;
            }
    }
    }
    return 0;
}
