#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
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

int getLength(Tree*& root)
{
    if(!root)
        return 0;
    return max(getLength(root->left), getLength(root->right)) + 1;
}

void getLeaf(Tree*& root, vector<char>& leaf, int length)
{
    if(length == 1)
    {
        leaf.push_back(root->val);
        return;
    }
    if(root && root->left)
        getLeaf(root->left, leaf, length-1);       
    if(root && root->right)
        getLeaf(root->right, leaf, length-1);
    
}

void solve(Tree*& root, map<char, map<char, int>>&mp)
{
    int l = getLength(root->left);
    vector<char> leftLeaf;    
    getLeaf(root->left, leftLeaf, l);
    int numLeft = leftLeaf.size();

    int r = getLength(root->right);
    vector<char> rightLeaf;
    getLeaf(root->right, rightLeaf, r);
    int numRight = rightLeaf.size();

    for(int i = 0; i < numLeft; ++i)
    {
        for(int j = 0; j < numRight; ++j)
        {
            mp[leftLeaf[i]][rightLeaf[j]] = mp[rightLeaf[j]][leftLeaf[i]] = l+r;
        }
        mp[root->val][leftLeaf[i]] = mp[leftLeaf[i]][root->val] = l;
    }
    for(int j = 0; j < numRight; ++j)
        mp[root->val][rightLeaf[j]] = mp[rightLeaf[j]][root->val] = r;
    if(root->left)
        solve(root->left, mp);
    if(root->right)
        solve(root->right, mp);
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
        if(!root || !root->left && !root->right)
        {
            cout << "0:" << endl;
            continue;
        }
        map<char, map<char, int>>mp;
        solve(root, mp);
        char first, second;
        int max = -1;
        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            for(auto itt = it->second.begin(); itt != it->second.end(); ++itt)
            {
                if(itt->second > max)
                {
                    max = itt->second;
                    first = it->first;
                    second = itt->first;
                }
            }
        }
        cout << max << ':' << first << ' ' << second << endl;
        clear(root);
    }
    return 0;
}