#include<iostream>
#include<string>
using namespace std;

struct Tree
{
    Tree *left, *right, *father;
    char val;
    Tree(char v = '?', Tree* l = nullptr, Tree* r = nullptr)
    {
        left = l, right = r, val = v;
    }
};

void generate(Tree*& tree)
{
    cin >> tree->val;
    if(tree->val == '0')
        return;
    tree->left = new Tree();
    tree->right = new Tree();
    generate(tree->left);
    generate(tree->right);
}

void findson(Tree*& tree)
{
    if(!tree)
        return;
    if(tree->left && tree->right)
        if(tree->left->val == '0' && tree->right->val == '0')
            cout << tree->val << ' ';
    findson(tree->left);
    findson(tree->right);
}

void findfather(Tree*& tree)
{
    if(!tree)
        return;
    if(tree->left)
    {
        if(tree->left->left && tree->left->right)
        {
            if(tree->left->left->val == '0' && tree->left->right->val == '0')
                cout << tree->val << ' ';
        }
        findfather(tree->left);
    }
    if(tree->right)
    {
        if(tree->right->left && tree->right->right)
        {
            if(tree->right->left->val == '0' && tree->right->right->val == '0')
                cout << tree->val << ' ';
        }
        findfather(tree->right);
    }
}

void clear(Tree*& root)
{
    if(root->left)
    {
        clear(root->left);
    }
    if(root->right)
    {
        clear(root->right);
    }
    delete root;
}

int main()
{
    int t; 
    cin >> t;
    while(t--)
    {
        Tree* root = new Tree();
        generate(root);
        findson(root);
        cout << endl;
        findfather(root);
        cout << endl;
        clear(root);
    }
    return 0;
}