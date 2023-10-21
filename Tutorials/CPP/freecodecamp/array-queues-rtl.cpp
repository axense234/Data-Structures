#include <iostream>
#define MAX_SIZE 5

using namespace std;

int head = -1;
int tail = -1;

bool isEmpty()
{
    return (head == -1 && tail == -1);
}

bool isFull()
{
    return (tail + 1) % MAX_SIZE == head;
}

void enqueue(int A[MAX_SIZE], int value)
{

    if (isFull())
    {
        cout << "Queue is full!" << endl;
        return;
    }
    else if (isEmpty())
    {
        head = 0;
        tail = 0;
    }
    else
    {
        tail = (tail + 1) % MAX_SIZE;
    }
    A[tail] = value;
}

int dequeue(int A[MAX_SIZE])
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    else if (tail == head)
    {
        head = -1;
        tail = -1;
    }
    else
    {
        head = (head + 1) % MAX_SIZE;
    }
    return A[(head + MAX_SIZE - 1) % MAX_SIZE];
}

int front(int A[MAX_SIZE])
{
    return A[head];
}

int rear(int A[MAX_SIZE])
{
    return A[tail];
}

void print(int A[MAX_SIZE])
{
    if (isEmpty())
    {
        return;
    }
    int i = head;
    do
    {
        cout << A[i % MAX_SIZE] << ' ';
        i++;
    } while ((i + MAX_SIZE - 1) % MAX_SIZE != tail);
    cout << endl;
}

int main()
{
    int A[MAX_SIZE];
    short option = 0;
    int value = 0;

    while (option != -1)
    {
        cout << "Option: " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Value: " << endl;
            cin >> value;
            cout << endl;
            enqueue(A, value);
            print(A);
            break;

        case 2:
            cout << "Removed from queue: " << dequeue(A) << endl;
            print(A);
            break;

        case 3:
            cout << "Front is: " << front(A) << endl;
            print(A);
            break;

        case 4:
            cout << "Rear is: " << rear(A) << endl;
            print(A);
            break;
        case 5:
            cout << "Queue is " << (isEmpty() ? "empty" : "not empty") << endl;
            print(A);
            break;
        case 6:
            cout << "Queue content:" << endl;
            print(A);
            break;
        case 7:
            cout << "Exiting program..." << endl;
            option = -1;
            break;
        default:
            cout << "Exiting program..." << endl;
            option = -1;
            break;
        }
    }

    return 0;
}
