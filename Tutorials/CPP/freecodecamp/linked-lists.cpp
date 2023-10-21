#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

typedef Node *list;

void insertBeginning(int x, list &head)
{
  Node *temp = new Node();
  temp->data = x;
  temp->next = head;

  head = temp;
}

void insertEnd(int x, list &head)
{
  Node *temp = new Node();
  temp->data = x;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
    return;
  }

  Node *temp1 = head;

  while (temp1->next != NULL)
  {
    temp1 = temp1->next;
  }
  temp1->next = temp;
}

void insertK(int x, int k, list &head)
{
  Node *temp1 = new Node();
  temp1->data = x;
  temp1->next = NULL;

  if (k == 1)
  {
    temp1->next = head;
    head = temp1;
    return;
  }

  Node *temp2 = head;
  for (int i = 0; i < k - 2; i++)
  {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void deleteK(int k, list &head)
{
  Node *temp1 = head;

  if (head == NULL)
  {
    cout << "list is empty..." << endl;
    return;
  }

  if (k == 1)
  {
    head = temp1->next;
    delete temp1;
    return;
  }

  for (int i = 0; i < k - 2; i++)
  {
    temp1 = temp1->next;
  }
  Node *temp2 = temp1->next;
  temp1->next = temp2->next;
  delete temp2;
}

void deleteEnd(list &head)
{
  Node *temp1 = head;

  if (head == NULL)
  {
    cout << "list is empty..." << endl;
    return;
  }

  while (temp1->next->next != NULL)
  {
    temp1 = temp1->next;
  }

  delete temp1->next;
  temp1->next = NULL;
}

void reverseListIteratively(list &head)
{
  if (head == NULL)
  {
    cout << "list is empty..." << endl;
    return;
  }

  Node *temp = head, *auxNode = NULL, *nextNode = head->next;
  while (temp != NULL)
  {
    nextNode = temp->next;
    temp->next = auxNode;
    auxNode = temp;
    temp = nextNode;
  }
  head = auxNode;
}

void reverseListRecursive(Node *currentNode, Node *prevNode, list &head)
{
  if (currentNode == NULL)
  {
    head = prevNode;
    return;
  }

  reverseListRecursive(currentNode->next, currentNode, head);
  currentNode->next = prevNode;
}

void printList(list head)
{
  Node *temp = head;

  if (head == NULL)
  {
    cout << "list is empty..." << endl;
    return;
  }

  cout << "List is: ";
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
      cout << "reversing linked list iteratively..." << endl;
      reverseListIteratively(head);
      printList(head);
      break;
    case 7:
      cout << "printing list..." << endl;
      printList(head);
      break;
    case 8:
      cout << "printing list using recursion in ascending order..." << endl;
      printListRecursiveForward(head);
      break;
    case 9:
      cout << "printing list using recursion in descending order..." << endl;
      printListRecursiveReverse(head);
      cout << endl;
      break;
    case 10:
      cout << "reversing list using recursion..." << endl;
      reverseListRecursive(head, NULL, head);
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