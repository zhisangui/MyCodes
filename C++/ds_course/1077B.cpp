#include<iostream>
using namespace std;
struct Tree
{
    char val;
    Tree *left, *right;
    Tree(char v, Tree* l = nullptr, Tree* r = nullptr)
    {
        val = v, left = l, right = r;
    }
};

void generateTree(Tree*& root)
{
    char data;
    cin >> data;
    if(data == '#')
    {
        root = nullptr;
        return;
    }
    root = new Tree(data);
    generateTree(root->left);
    generateTree(root->right);
}

void reverse(Tree*& root)
{
    if(!root || (!root->left && !root->right))
        return;
    Tree* temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}

void preOrder(Tree*& root)
{
    if(!root)
        return;
    cout << root->val << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Tree*& root)
{
    if(!root)
        return;
    inOrder(root->left);
    cout << root->val << ' ';
    inOrder(root->right);
}

void postOrder(Tree*& root)
{
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << ' ';
}

int getLength(Tree*& root)
{
    if(!root)
        return 0;
    int l = getLength(root->left);
    int r = getLength(root->right);
    return l>r ? l+1 : r+1;
}

void Print(Tree*& root, int curr, int target)
{
    if(curr == target)
    {
        cout << root->val << ' ';
        return;
    }
    if(root->left)
        Print(root->left, curr+1, target);
    if(root->right)
        Print(root->right, curr+1, target);
}

void leverOrder(Tree*& root)
{
    if(!root)
        return;
    int maxLength = getLength(root);
    for(int i = 1; i <= maxLength; ++i)
        Print(root, 1, i);
}

void clear(Tree*& root)
{
    if(!root)
        return;
    clear(root->left);
    clear(root->right);
    delete root;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        Tree* root;
        generateTree(root);
        reverse(root);
        if(!root)
        {
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            continue;
        }
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        leverOrder(root);
        cout << endl;
        clear(root);
    }
    return 0;
}
