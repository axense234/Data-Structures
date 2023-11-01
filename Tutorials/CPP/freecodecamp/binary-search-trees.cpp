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

bool isSubtreeLesser(node *root, int value)
{
    if (root == NULL)
        return true;
    return root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value);
}

bool isSubtreeGreater(node *root, int value)
{
    if (root == NULL)
        return true;
    return root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value);
}

bool isBST(node *root)
{
    if (root == NULL)
        return true;
    return isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && isBST(root->left) && isBST(root->right);
}

bool isBSTEfficient(node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    return root->data > minValue && root->data < maxValue && isBSTEfficient(root->left, minValue, root->data) && isBSTEfficient(root->right, root->data, maxValue);
}

node *findMinBST(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    return findMinBST(root->left);
}

node *findMaxBST(node *root)
{
    if (root->left == NULL && root->left == NULL)
    {
        return root;
    }
    return findMaxBST(root->right);
}

node *deleteNodeRecursive(node *root, int value)
{
    // Moving recursively through the tree until node with given value is found
    if (root == NULL)
        return root;
    else if (value < root->data)
    {
        root->left = deleteNodeRecursive(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNodeRecursive(root->right, value);
    }
    // We found the node with given value
    else
    {
        // 0 Children Node Deletion
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            // 1 Children Node Deletion
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
            // 2 Children Node Deletion;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            node *temp = findMinBST(root->right);
            root->data = temp->data;
            root->right = deleteNodeRecursive(root->right, temp->data);
        }
    }
    return root;
}

void deleteNodeIterative(node *root, int value)
{
    if (root == NULL)
    {
        return;
    }

    node *parentNode = NULL;
    node *currentNode = root;

    while (currentNode && currentNode->data != value)
    {
        if (value < currentNode->data)
        {
            parentNode = currentNode;
            currentNode = currentNode->left;
        }
        else if (value > currentNode->data)
        {
            parentNode = currentNode;
            currentNode = currentNode->right;
        }
    }

    // We either found our node or we didn't
    if (currentNode == NULL)
    {
        return;
        // Leaf Node Deletion
    }
    else if (currentNode->left == NULL && currentNode->right == NULL)
    {
        if (parentNode->left->data == currentNode->data)
        {
            parentNode->left = NULL;
            delete currentNode;
        }
        else if (parentNode->right->data == currentNode->data)
        {
            parentNode->right = NULL;
            delete currentNode;
        }
        // Node with 1 child Deletion
    }
    else if (currentNode->left == NULL || currentNode->right == NULL)
    {
        if (parentNode->left->data == currentNode->data)
        {
            if (currentNode->left == NULL)
            {
                parentNode->left = currentNode->right;
            }
            else if (currentNode->right == NULL)
            {
                parentNode->left = currentNode->left;
            }
            delete currentNode;
        }
        else if (parentNode->right->data == currentNode->data)
        {
            if (currentNode->left == NULL)
            {
                parentNode->right = currentNode->right;
            }
            else if (currentNode->right == NULL)
            {
                parentNode->right = currentNode->left;
            }
            delete currentNode;
        }
        // Node with 2 children Deletion
    }
    else if (currentNode->left != NULL && currentNode->right != NULL)
    {
        // If the left subtree only has 1 node(so it is a leaf node basically)
        if (currentNode->left->left == NULL && currentNode->left->right == NULL)
        {
            currentNode->data = currentNode->left->data;
            currentNode->left = NULL;
            delete currentNode->left;
            // If the left subtree has more than 1 node
        }
        else if (currentNode->left->left == NULL || currentNode->left->right == NULL)
        {
            node *max = currentNode->left;
            node *maxParent = currentNode;

            while (max->right != NULL)
            {
                maxParent = max;
                max = max->right;
            }

            currentNode->data = max->data;
            // Deleting the max node based on number of children it has(can have 0 or only 1 that is on the left side)
            if (max->left == NULL && max->right == NULL)
            {
                maxParent->right = NULL;
                delete max;
            }
            else if (max->left != NULL)
            {
                maxParent->left = max->left;
                delete max;
            }
        }
    }
}

node *getInorderSuccesor(node *root, int data)
{
    node *current = root;
    while (current != NULL && current->data != data)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
    }

    if (current == NULL)
    {
        return current;
    }

    // Node has right subtree
    if (current->right != NULL)
    {
        return findMinBST(current->right);
    }

    // Node does not have right subtree
    else if (current->right == NULL)
    {
        node *succesor = NULL;
        node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                succesor = ancestor;
                ancestor = ancestor->left;
            }
            else if (current->data > ancestor->data)
            {
                ancestor = ancestor->right;
            }
        }
        return succesor;
    }
    else
    {
        return root;
    }
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
    cout << "is the binary tree a BST?: " << isBST(rootBST) << endl;
    cout << "is the binary tree a BST?(efficient version): " << isBSTEfficient(rootBST, INT_MIN, INT_MAX) << endl;

    int value = 0;
    // cout << "Enter value of node to be deleted: " << endl;
    cout << "Enter value of node to find it's succesor: " << endl;
    cin >> value;
    inOrderTraversalBST(rootBST);
    cout << endl;
    // rootBST = deleteNodeRecursive(rootBST, value);
    node *foundNode = getInorderSuccesor(rootBST, value);
    if (foundNode)
    {
        cout << foundNode->data << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    inOrderTraversalBST(rootBST);
    cout << endl;

    // int searchValue = 0;
    // cout << "Enter search value: ";
    // cin >> searchValue;
    // // searchTreeRecursive(rootBST, searchValue) ? cout << "Found\n" : cout << "Not Found\n";
    // searchTreeIterative(rootBST, searchValue) ? cout << "Found\n" : cout << "Not Found\n";

    return 0;
}