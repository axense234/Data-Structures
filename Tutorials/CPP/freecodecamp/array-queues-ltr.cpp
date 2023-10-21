#include <iostream>
#define MAX_SIZE 5

using namespace std;

int head = -1;
int tail = 0;

void enqueue(int A[MAX_SIZE], int value)
{

    if (head == -1)
    {
        A[0] = value;
        head++;
        return;
    }

    if (head == MAX_SIZE - 1)
    {
        cout << "Queue is full!" << endl;
        return;
    }

    for (int i = head; i >= 0; i--)
    {
        A[i + 1] = A[i];
    }
    A[0] = value;
    head++;
}

int dequeue(int A[MAX_SIZE])
{
    if (head < 1)
    {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    return A[head--];
}

bool isEmpty()
{
    return head == -1;
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
    for (int i = 0; i <= head; i++)
    {
        cout << A[i] << ' ';
    }
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
