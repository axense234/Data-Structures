#include <iostream>
#define MAXSIZE 1000

using namespace std;

void showK(int A[MAXSIZE], int n)
{
  if (!n)
  {
    cout << "the list is empty" << endl;
  }
  else
  {
    int k;
    cout << "position k: ";
    cin >> k;
    if (k > n)
    {
      k = 1;
    }
    cout << A[k - 1] << endl;
  }
}

void showList(int A[MAXSIZE], int n)
{
  if (!n)
  {
    cout << "the list is empty" << endl;
  }
  else
  {

    for (int i = 0; i < n; i++)
    {
      cout << "element"
           << "(" << i << "): " << A[i] << endl;
    }
  }
}

void addEnd(int A[MAXSIZE], int &n)
{
  cout << "last element: ";
  cin >> A[n];
  n++;
}

void addFirst(int A[MAXSIZE], int &n)
{
  for (int i = n; i >= 0; i--)
  {
    A[i + 1] = A[i];
  }
  n++;
  cout << "first element: ";
  cin >> A[0];
}

void remEnd(int A[MAXSIZE], int &n)
{
  if (!n)
  {
    cout << "the list is empty" << endl;
  }
  else
  {
    A[n] = 0;
    n--;
  }
}

void remFirst(int A[MAXSIZE], int &n)
{
  if (!n)
  {
    cout << "the list is empty" << endl;
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      A[i] = A[i + 1];
    }
    n--;
  }
}

void addK(int A[MAXSIZE], int &n)
{
  int k;
  cout << "position k: ";
  cin >> k;

  if (k > n)
  {
    k = 1;
  }

  for (int i = n; i >= k; i--)
  {
    A[i + 1] = A[i];
  }

  cout << "element at k position: ";
  cin >> A[k];
  n++;
}

void remK(int A[MAXSIZE], int &n)
{
  if (!n)
  {
    cout << "the list is empty" << endl;
  }
  else
  {
    int k;
    cout << "position k: ";
    cin >> k;

    if (k > n)
    {
      k = 1;
    }

    for (int i = k; i < n; i++)
    {
      A[i] = A[i + 1];
    }
    n--;
  }
}

int main()
{
  int A[MAXSIZE];
  int n = 0;
  short int option;

  while (option != 0)
  {
    cout << "option: ";
    cin >> option;

    switch (option)
    {
    case 1:
      // Show list
      showList(A, n);
      break;
    case 2:
      // Add element at the end of the list
      addEnd(A, n);
      break;
    case 3:
      // Add element at the beginning of the list
      addFirst(A, n);
      break;
    case 4:
      // Remove element at the end of the list
      remEnd(A, n);
      break;
    case 5:
      // Remove element at the beginning of the list
      remFirst(A, n);
      break;
    case 6:
      // Add element at position k
      addK(A, n);
      break;
    case 7:
      // Remove element at position k
      remK(A, n);
      break;
    case 8:
      // Show element at k position in the list
      showK(A, n);
      break;
    default:
      cout << "exiting program" << endl;
      break;
    }
  }

  return 0;
}