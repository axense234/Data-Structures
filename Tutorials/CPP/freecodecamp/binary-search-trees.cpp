#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *rootBST = NULL;

node *createNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *insertRecursive(node *root, int data)
{

    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertRecursive(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertRecursive(root->right, data);
    }
    return root;
}

node *insertIterative(node *root, int data)
{
    node *temp = createNode(data);
    if (root == NULL)
    {
        root = temp;
        return root;
    }

    node *traverse = root;
    while (traverse->left != NULL && traverse->right != NULL)
    {
        if (temp->data <= traverse->data)
        {
            traverse = traverse->left;
        }
        else if (temp->data > traverse->data)
        {
            traverse = traverse->right;
        }
    }

    if (temp->data <= traverse->data)
    {
        traverse->left = temp;
    }
    else if (temp->data > traverse->data)
    {
        traverse->right = temp;
    }
    return root;
}

bool searchTreeRecursive(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return searchTreeRecursive(root->left, data);
    }
    else
    {
        return searchTreeRecursive(root->right, data);
    }
}

bool searchTreeIterative(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    node *traverse = root;
    while (traverse->left != NULL || traverse->right != NULL)
    {
        if (data == traverse->data)
        {
            return true;
        }

        if (data < traverse->data)
        {
            traverse = traverse->left;
        }
        else if (data > traverse->data)
        {
            traverse = traverse->right;
        }
    }

    return data == traverse->data;
}

int main()
{
    rootBST = insertRecursive(rootBST, 10);
    rootBST = insertIterative(rootBST, 20);
    rootBST = insertRecursive(rootBST, 2);
    rootBST = insertIterative(rootBST, 5);
    rootBST = insertRecursive(rootBST, 35);
    rootBST = insertIterative(rootBST, 12);

    int searchValue = 0;
    cout << "Enter search value: ";
    cin >> searchValue;
    searchTreeRecursive(rootBST, searchValue) ? cout << "Found\n" : cout << "Not Found\n";
    searchTreeIterative(rootBST, searchValue) ? cout << "Found\n" : cout << "Not Found\n";

    return 0;
}