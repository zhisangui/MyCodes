#include<iostream>
#include<string>
#include<queue>
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

int length(Tree*& root)
{
    queue<Tree*> q;
    q.push(root);
    int layer = 0;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            Tree* temp = q.front();
            q.pop();
            if(temp->left && temp->left->val != '0')
                q.push(temp->left);
            if(temp->right && temp->right->val != '0')
                q.push(temp->right);
        }
        layer++;
    }
    return layer;
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
        cout << length(root) << endl;
        clear(root);
    }
    return 0;
}

 