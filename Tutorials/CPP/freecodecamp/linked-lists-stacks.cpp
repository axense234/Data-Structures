#include <iostream>
#include <cstring>
#include <stack> // stack from standard template library(stl)
using namespace std;

struct node
{
  int data;
  node *next;
};

node *top = NULL;

char stringArray[101];

node *createNode(int x)
{
  node *newNode = new node();
  newNode->data = x;
  newNode->next = NULL;
  return newNode;
}

void push(int x)
{
  node *newNode = createNode(x);
  newNode->next = top;
  top = newNode;
}

void pop()
{
  if (top == NULL)
  {
    cout << "stack is empty..." << endl;
    return;
  }

  if (top->next == NULL)
  {
    delete top;
    top = NULL;
    return;
  }

  node *temp = top;
  top = top->next;
  delete temp;
}

void showStackContent()
{
  if (top == NULL)
  {
    cout << "stack is empty..." << endl;
    return;
  }
  node *temp = top;
  while (temp != NULL)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}

int getTop()
{
  return top->data;
}

bool isStackEmpty()
{
  if (top == NULL)
  {
    return true;
  }
  return false;
}

void reverseStringUsingCString()
{
  char string[] = "HELLO";
  strrev(string);
  cout << string << endl;
}

void reverseUsingStackFromLib(int stringLength)
{
  stack<char> S;
  for (int i = 0; i < stringLength; i++)
  {
    S.push(stringArray[i]);
  }

  for (int i = 0; i < stringLength; i++)
  {
    stringArray[i] = S.top();
    S.pop();
  }

  cout << stringArray << endl;
}

void reverseLinkedListUsingStack()
{
  if (top == NULL || top->next == NULL)
  {
    return;
  }

  stack<node *> S;
  node *temp = top;

  while (temp != NULL)
  {
    S.push(temp);
    temp = temp->next;
  }

  temp = S.top();
  top = temp;
  S.pop();
  while (!S.empty())
  {
    temp->next = S.top();
    S.pop();
    temp = temp->next;
  }
  temp->next = NULL;
}

bool isOpeningSymbol(char symbol)
{
  return symbol == '(' || symbol == '[' || symbol == '{';
}

bool isClosingSymbol(char symbol)
{
  return symbol == ')' || symbol == ']' || symbol == '}';
}

bool matchingSymbols(char openingSymbol, char closingSymbol)
{
  if (openingSymbol == '(' && closingSymbol == ')')
  {
    return true;
  }
  else if (openingSymbol == '[' && closingSymbol == ']')
  {
    return true;
  }
  else if (openingSymbol == '{' && closingSymbol == '}')
  {
    return true;
  }
  return false;
}

bool balancedParentheses(int stringLength)
{
  if (stringLength <= 1)
  {
    return false;
  }

  stack<char> openingParentheses;
  for (int i = 0; i < stringLength; i++)
  {
    if (isOpeningSymbol(stringArray[i]))
    {
      openingParentheses.push(stringArray[i]);
    }
    else if (isClosingSymbol(stringArray[i]))
    {
      if (openingParentheses.empty() || !matchingSymbols(openingParentheses.top(), stringArray[i]))
      {
        return false;
      }
      else
      {
        openingParentheses.pop();
      }
    }
  }

  return openingParentheses.empty();
}

bool isOperator(char possibleOperator)
{
  return possibleOperator == '*' || possibleOperator == '/' || possibleOperator == '-' || possibleOperator == '+';
}

// op1 = char of a string, op2 = top of a stack
bool hasLowerPrecedence(char op1, char op2)
{
  return (op2 == '*' || op2 == '/') && (op1 == '+' || op1 == '-');
}

char *infixToPostfix(char *expression)
{
  char *newExpression = new char(strlen(expression));
  strcpy(newExpression, expression);
  // Specific Cases
  if (strlen(expression) < 3)
  {
    cout << "expression does not have enough tokens..." << endl;
    return expression;
  }
  else if (strlen(expression) == 3)
  {
    newExpression[0] = expression[0];
    newExpression[1] = expression[2];
    newExpression[2] = expression[1];
    return newExpression;
  }
  // General Cases
  stack<char> operators;
  short int k = 0;
  for (int i = 0; i < strlen(expression); i++)
  {
    if (isdigit(expression[i]))
    {
      newExpression[k++] = expression[i];
    }
    else if (isOperator(expression[i]))
    {
      if (!operators.empty())
      {
        if (hasLowerPrecedence(expression[i], operators.top()))
        {
          while (!operators.empty())
          {
            newExpression[k++] = operators.top();
            operators.pop();
          }
        }
      }
      operators.push(expression[i]);
    }
  }
  while (!operators.empty())
  {
    newExpression[k++] = operators.top();
    operators.pop();
  }
  return newExpression;
}

int main()
{
  cout << "string array: ";
  cin.getline(stringArray, 100);

  int option = -1, x;
  char *newArray;
  while (option != 0)
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
      showStackContent();
      break;
    case 2:
      cout << "popping..." << endl;
      pop();
      showStackContent();
      break;
    case 3:
      showStackContent();
      break;
    case 4:
      cout << "top: " << getTop() << endl;
      break;
    case 5:
      cout << "list is empty: " << isStackEmpty() << endl;
      break;
    case 6:
      reverseStringUsingCString();
      break;
    case 7:
      reverseUsingStackFromLib(strlen(stringArray));
      break;
    case 8:
      reverseLinkedListUsingStack();
      showStackContent();
      break;
    case 9:
      cout << "parentheses are balanced: " << balancedParentheses(strlen(stringArray)) << endl;
      break;
    case 10:
      cout << "original expression(infix): " << stringArray << endl;
      newArray = infixToPostfix(stringArray);
      cout << "new expression(postfix): " << newArray << endl;
      delete newArray;
      break;
    default:
      cout << "ending program..." << endl;
      break;
    }
  }

  return 0;
}