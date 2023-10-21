#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};

typedef Node *list;

void printList(list &head)
{
  Node *temp = head;

  if (head != NULL)
  {
    cout << "List is: ";
  }
  while (temp != NULL)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}

void printListRecursiveForward(Node *currentNode)
{
  if (currentNode == NULL)
  {
    cout << endl;
    return;
  }

  cout << currentNode->data << ' ';
  printListRecursiveForward(currentNode->next);
}

void printListRecursiveReverse(Node *currentNode)
{
  if (currentNode == NULL)
  {
    return;
  }

  printListRecursiveReverse(currentNode->next);
  cout << currentNode->data << ' ';
}

int getListSize(list head)
{
  int nbNodes = 0;
  while (head != NULL)
  {
    nbNodes++;
    head = head->next;
  }
  return nbNodes;
}

Node *getNewNode(int x)
{
  Node *newNode = new Node();
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void insertBeginning(int x, list &head)
{
  Node *newNode = getNewNode(x);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void insertEnd(int x, list &head)
{
  Node *newNode = getNewNode(x);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *t = head;
  while (t->next != NULL)
  {
    t = t->next;
  }
  t->next = newNode;
  newNode->prev = t;
}

void insertK(int x, int k, list &head)
{
  if (k < 1)
  {
    cout << "k should be at least 1!" << endl;
    return;
  }

  Node *newNode = getNewNode(x);

  if (head == NULL)
  {
    head = newNode;
    return;
  }

  if (k == 1)
  {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
  }

  Node *t = head;
  int i, nbNodes = getListSize(head);

  for (i = 0; i < k - 2; i++)
  {
    if (i + 2 >= nbNodes)
    {
      t->next->next = newNode;
      newNode->prev = t->next;
      newNode->next = NULL;
      return;
    }
    t = t->next;
  }

  newNode->prev = t;
  newNode->next = t->next;
  t->next = newNode;
  newNode->next->prev = newNode;
}

void deleteK(int k, list &head)
{

  if (k < 1)
  {
    cout << "k should be at least 1!" << endl;
    return;
  }

  if (head == NULL)
  {
    cout << "list is empty..." << endl;
    return;
  }

  if (head->next == NULL)
  {
    head = NULL;
    return;
  }

  if (k == 1)
  {
    head = head->next;
    delete head->prev;
    head->prev = NULL;
    return;
  }

  Node *t = head;
  int i, nbNodes = getListSize(head);
  for (int i = 0; i < k - 1; i++)
  {
    if (i + 1 >= nbNodes)
    {
      t->prev->next = NULL;
      delete t;
      return;
    }
    t = t->next;
  }
  t->prev->next = t->next;
  if (t->next != NULL)
  {
    t->next->prev = t->prev;
  }
  delete t;
}

void deleteEnd(list &head)
{
  if (head == NULL)
  {
    cout << "list is empty..." << endl;
    return;
  }

  if (head->next == NULL)
  {
    head = NULL;
    return;
  }

  Node *t = head;
  while (t->next->next != NULL)
  {
    t = t->next;
  }

  delete t->next;
  t->next = NULL;
}

void reverseList(list &head)
{
  if (head == NULL)
  {
    cout << "list is empty..." << endl;
    return;
  }

  Node *currentNode = head, *nextNode = head->next;
  while (currentNode->next != NULL)
  {
    nextNode = currentNode->next;
    currentNode->next = currentNode->prev;
    currentNode->prev = nextNode;
    currentNode = nextNode;
  }
  currentNode->next = currentNode->prev;
  currentNode->prev = NULL;
  head = currentNode;
}

void reverseListRecursive(Node *currentNode, list &head)
{
  if (currentNode == NULL)
  {
    head = currentNode->prev;
    return;
  }

  reverseListRecursive(currentNode->next, head);
  cout << currentNode->data << ' ';
}

int main()
{
  list head = NULL;
  int x, option = -1, k;

  while (option != 0)
  {
    cout << "Option: ";
    cin >> option;
    switch (option)
    {
    case 1:
      cout << "Element: ";
      cin >> x;
      insertBeginning(x, head);
      printList(head);
      break;
    case 2:
      cout << "Element: ";
      cin >> x;
      cout << "Position k: ";
      cin >> k;
      insertK(x, k, head);
      printList(head);
      break;
    case 3:
      cout << "Element: ";
      cin >> x;
      insertEnd(x, head);
      printList(head);
      break;
    case 4:
      cout << "Position k: ";
      cin >> k;
      deleteK(k, head);
      printList(head);
      break;
    case 5:
      cout << "deleting end..." << endl;
      deleteEnd(head);
      printList(head);
      break;
    case 6:
      cout << "printing list..." << endl;
      printList(head);
      break;
    case 7:
      cout << "printing list in ascending order using recursion..." << endl;
      printListRecursiveForward(head);
      break;
    case 8:
      cout << "printing list in descending order using recursion..." << endl;
      printListRecursiveReverse(head);
      cout << endl;
      break;
    case 9:
      cout << "reversing list iteratively..." << endl;
      reverseList(head);
      printList(head);
      break;
    case 10:
      cout << "reversing list recursive..." << endl;
      reverseListRecursive(head, head);
      printList(head);
      break;
    default:
      cout << "exiting program..." << endl;
      option = 0;
      break;
    }
  }

  return 0;
}