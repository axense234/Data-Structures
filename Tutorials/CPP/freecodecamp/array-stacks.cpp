#include <iostream>
#define MAX_SIZE 101

using namespace std;

int A[MAX_SIZE], top = -1;

void push(int x)
{
  if (top == MAX_SIZE - 1)
  {
    cout << "Error: Stack Overflow" << endl;
    return;
  }
  A[++top] = x;
}

void pop()
{
  if (top == -1)
  {
    cout << "Error: No Element to Pop" << endl;
    return;
  }
  top--;
}

void showTop()
{
  cout << "top: " << A[top] << endl;
}

bool emptyStack()
{
  if (top < 0)
  {
    return true;
  }
  return false;
}

void showStackContent()
{
  for (int i = 0; i <= top; i++)
  {
    cout << A[i] << ' ';
  }
  cout << endl;
}

int main()
{
  int option = -1, x;
  while (option)
  {
    cout << "option: ";
    cin >> option;
    switch (option)
    {
    case 1:
      cout << "element to push: ";
      cin >> x;
      cout << "pushing..." << endl;
      push(x);
      break;
    case 2:
      cout << "popping..." << endl;
      pop();
      break;
    case 3:
      cout << "stack is empty: " << emptyStack() << endl;
      break;
    case 4:
      cout << "displaying stack content..." << endl;
      showStackContent();
      break;
    case 5:
      showTop();
      break;
    default:
      cout << "ending program..." << endl;
      option = 0;
      break;
    }
  }

  return 0;
}