#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct Tree
{
    int val;
    Tree*left, *right;
    Tree(int v = -1)
    {
        val = v;
        left = right = nullptr;
    }
};

void generateTree(Tree*& root, map<int, int>&index,  vector<int>&inorder, vector<int>&postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right)
{
    if(inorder_left > inorder_right)
        return;
    int root_post = postorder_right;
    int root_val = postorder[root_post];
    int root_inorder = index[root_val];
    int leftsize = root_inorder - inorder_left;
    root = new Tree(root_val);
    generateTree(root->left, index, inorder, postorder, inorder_left, root_inorder-1, postorder_left, postorder_left+leftsize-1);
    generateTree(root->right, index, inorder, postorder, root_inorder+1, inorder_right, postorder_left+leftsize, postorder_right-1);
}

void solve(Tree*& root, vector<int>& ans)
{   
    if(!root)
        return;
    if(!root->left && !root->right)
        ans.push_back(root->val);
    if(root->left)
        solve(root->left, ans);
    if(root->right)
        solve(root->right, ans);
}

void destory(Tree*& root)
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
        int n;
        cin >> n;
        map<int, int>index;
        vector<int> inorder(n,0), postorder(n, 0);
        for(int i = 0; i < n; ++i)
        {
            cin >> inorder[i];
        }
        for(int i = 0; i < n; ++i)
        {
            cin >> postorder[i];
        }
        for(int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }
        Tree* root;
        generateTree(root, index, inorder, postorder, 0, n-1, 0, n-1);
        vector<int>ans;
        solve(root, ans);    
        int num = ans.size();
        int res = ans[0];
        for(int i = 0; i < num; ++i)
            res = min(res, ans[i]);
        cout << res << endl;
        destory(root);
    }
    return 0;
}