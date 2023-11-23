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
    if(tree->val == '#')
        return;
    tree->left = new Tree();
    tree->right = new Tree();
    generate(tree->left);
    generate(tree->right);
}

void preorder(Tree* &tree)
{
    if(!tree || tree->val == '#')
        return;
    cout << tree->val;
    preorder(tree->left);
    preorder(tree->right);
}

void inorder(Tree* &tree)
{
    if(!tree || tree->val == '#')
        return;
    inorder(tree->left);
    cout << tree->val;
    inorder(tree->right);
}

void postorder(Tree* &tree)
{
    if(!tree || tree->val == '#')
        return;
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->val;
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
        preorder(root);
        cout << endl;
        inorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
        clear(root);
    }
    return 0;
}
