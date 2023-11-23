#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

struct Tree
{
    char c;
    int weight;
    Tree* left, *right;
    Tree(char cc = '?', int ww = -1)
    {
        c = cc;
        weight = ww;
        left = right = nullptr;
    }
};

void buildTree(Tree*& root, string str, int &curr)
{
    char c = str[curr];
    if(c == '0')
        return;
    else
    {
        int val;
        cin >> val;
        root = new Tree(c, val);
        buildTree(root->left, str, ++curr);
        buildTree(root->right, str, ++curr);
    }
}

int getMaxPath(Tree*& root)
{
    if(!root)
        return 0;
    return root->weight + max(getMaxPath(root->left), getMaxPath(root->right));
}

void destroy(Tree*& root)
{
    if(!root)
        return;
    if(root->left)
        destroy(root->left);
    if(root->right)
        destroy(root->right);
    delete root;    
}

int main()
{   
    int t;
    cin >> t;
    while(t--)
    {
        Tree* root;
        string str;
        cin >> str;
        int occupied;
        cin >> occupied;
        int curr = 0;
        buildTree(root, str, curr);
        cout << getMaxPath(root) << endl;
        destroy(root);
    }
    return 0;
}   