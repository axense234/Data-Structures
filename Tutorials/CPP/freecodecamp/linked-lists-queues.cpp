#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

node *createNode(int value)
{
    node *temp = new node();
    temp->data = value;
    temp->next = NULL;
    return temp;
}

bool isEmpty()
{
    return front == NULL && rear == NULL;
}

void enqueue(int value)
{
    node *temp = createNode(value);
    if (isEmpty())
    {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue()
{
    if (isEmpty())
    {
        cout << endl
             << "empty list!" << endl;
        return 0;
    }

    if (rear == front)
    {
        int deletedValue = front->data;
        front = NULL;
        rear = NULL;
        return deletedValue;
    }

    node *temp = front;
    int deletedValue = temp->data;
    front = front->next;
    delete temp;
    return deletedValue;
}

void print()
{
    node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

int head()
{
    return front->data;
}

int tail()
{
    return rear->data;
}

int main()
{
    short option = -1;
    int value = 0;
    while (option != 0)
    {
        cout << "Option: " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Value for enqueue: ";
            cin >> value;
            enqueue(value);
            print();
            break;
        case 2:
            cout << "Dequeue in progress..." << endl;
            cout << "Value dequeued: " << dequeue() << endl;
            print();
            break;
        case 3:
            cout << "Front of queue is: " << head() << endl;
            print();
            break;
        case 4:
            cout << "Rear of queue is: " << tail() << endl;
            print();
            break;
        case 5:
            cout << "Printing queue..." << endl;
            print();
            break;
        default:
            option = 0;
            break;
        }
    }

    return 0;
}