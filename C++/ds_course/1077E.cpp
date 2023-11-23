#include<iostream>
#include<string>
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

void buildTree(Tree*& root, string str, int curr, int size)
{
    if(curr < size && str[curr] != '#')
    {
        root = new Tree(str[curr]);
        buildTree(root->left, str, 2*curr+1, size);
        buildTree(root->right, str, 2*curr+2, size);
    }
}

bool isEqual(Tree*& root1, Tree*& root2)
{
    if((!root1 && root2) || (!root2 && root1))
        return false;
    if(!root1 && !root2)
        return true;
    return root1->val == root2->val && isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
}

void generateTree(Tree*& root, string str, int& curr, int size)
{
    if(curr >= size)
        return;
    char data = str[curr];
    if(data == '#')
        return;
    root = new Tree(data);
    curr++;
    generateTree(root->left, str, curr, size);
    curr++;
    generateTree(root->right, str, curr, size);
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
        Tree* root1, *root2;
        string str;
        cin >> str;
        buildTree(root1, str, 0, str.size());
        cin >> str;
        int curr = 0;
        generateTree(root2, str, curr, str.size());
        if(isEqual(root1, root2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        clear(root1);
        clear(root2);
    }
    return 0;
}