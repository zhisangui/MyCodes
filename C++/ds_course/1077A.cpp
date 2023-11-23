#include<iostream>
#include<stack>
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
    if(data == '0')
    {
        root = nullptr;
        return;
    }
    root = new Tree(data);
    generateTree(root->left);
    generateTree(root->right);
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
        Tree *pre = nullptr, *p = root;
        stack<Tree*> s;
        while(!s.empty() || p)
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            if(p->right && p->right != pre)
            {
                p = p->right;
            }
            else
            {
                cout << p->val;
                s.pop();
                pre = p;
                p = nullptr;
            }
        }
        clear(root);
        cout << endl;
    }
    return 0;
}
