#include<iostream>
#include<string>
using namespace std;

int ans = 0;
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

void findson(Tree*& tree, string flag)
{
    if(!tree)
        return;
    if(flag == "left")
    {
        if(tree->left && tree->right)
        {
            if(tree->left->val == '0' && tree->right->val == '0')
                ans++;
        }
    }
    findson(tree->left, "left");
    findson(tree->right, "right");
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
        ans = 0;
        Tree* root = new Tree();
        generate(root);
        findson(root, "right");  // root不能当做左节点
        cout << ans << endl;
        clear(root);
    }
    return 0;
}