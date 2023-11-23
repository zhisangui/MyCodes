#include<iostream>
#include<vector>
using namespace std;

struct Tree
{
    Tree* left, *right;
    int level;
    char val;
    Tree(char v, int ll = 0, Tree* l = nullptr, Tree* r = nullptr)
    {
        val = v;
        level = ll;
        left = l;
        right = r;
    }
};

void buildTree(Tree*& root, int level)
{
    char c;
    cin >> c;
    if(c == '0')
        return;
    else
    {
        root = new Tree(c, level);
        buildTree(root->left, level+1);
        buildTree(root->right, level+1);
    }
}

int getWeight(Tree*& root, vector<int> weight, int& curr)
{
    if(!root)
        return 0;
    int ans = 0;
    if(root->val >= 'A' && root->val <= 'Z')
        ans = weight[curr++] * root->level;
    int left = getWeight(root->left, weight, curr);
    int right = getWeight(root->right, weight, curr);
    return ans + left + right;
}

void destory(Tree* &root)
{
    if(!root)
        return;
    destory(root->left);
    destory(root->right);
    delete root;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        Tree* root;
        buildTree(root, 0);
        int n;
        cin >> n;
        vector<int> weight(n,0);
        for(int i =0; i < n; ++i)
            cin >> weight[i];
            int curr = 0;
        cout << getWeight(root, weight, curr) << endl;
        destory(root);
    }
    return 0;
}