#include <iostream>
#include <cmath>
#include <queue>
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

int findMinIterativeBST()
{
    if (rootBST == NULL)
    {
        cout << "Tree is empty!" << endl;
        return 0;
    }
    node *temp = rootBST;
    int min = temp->data;
    while (temp != NULL)
    {
        min = temp->data;
        temp = temp->left;
    }
    return min;
}

int findMaxIterativeBST()
{
    if (rootBST == NULL)
    {
        cout << "Tree is empty!" << endl;
        return 0;
    }
    node *temp = rootBST;
    int max = temp->data;
    while (temp != NULL)
    {
        max = temp->data;
        temp = temp->right;
    }
    return max;
}

int findMinRecursiveBST(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return 0;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return findMinRecursiveBST(root->left);
}

int findMaxRecursiveBST(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return 0;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return findMaxRecursiveBST(root->right);
}

int findMaxHeight(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    return max(findMaxHeight(root->left), findMaxHeight(root->right)) + 1;
}

void levelOrderTraversalBST(node *root)
{
    if (root == NULL)
        return;
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node *current = Q.front();
        cout << current->data << ' ';
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}

void preOrderTraversalBST(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ' ';
    preOrderTraversalBST(root->left);
    preOrderTraversalBST(root->right);
}

void inOrderTraversalBST(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversalBST(root->left);
    cout << root->data << ' ';
    inOrderTraversalBST(root->right);
}

void postOrderTraversalBST(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversalBST(root->left);
    inOrderTraversalBST(root->right);
    cout << root->data << ' ';
}

int main()
{
    rootBST = insertRecursive(rootBST, 10);
    rootBST = insertIterative(rootBST, 20);
    rootBST = insertRecursive(rootBST, 2);
    rootBST = insertIterative(rootBST, 5);
    rootBST = insertRecursive(rootBST, 35);
    rootBST = insertIterative(rootBST, 12);

    cout << "Min value in BST: " << findMinRecursiveBST(rootBST) << endl;
    cout << "Max value in BST: " << findMaxRecursiveBST(rootBST) << endl;
    cout << "Max height in BST: " << findMaxHeight(rootBST) << endl;
    // levelOrderTraversalBST(rootBST);
    preOrderTraversalBST(rootBST);
    cout << endl;
    inOrderTraversalBST(rootBST);
    cout << endl;
    postOrderTraversalBST(rootBST);
    cout << endl;

    // int searchValue = 0;
    // cout << "Enter search value: ";
    // cin >> searchValue;
    // // searchTreeRecursive(rootBST, searchValue) ? cout << "Found\n" : cout << "Not Found\n";
    // searchTreeIterative(rootBST, searchValue) ? cout << "Found\n" : cout << "Not Found\n";

    return 0;
}