#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct Tree
{
    char val;
    Tree* left, *right;
    Tree(char v, Tree* l = nullptr, Tree* r = nullptr)
    {
        val = v;
        left = l;
        right = r;
    }
};

int solve(char a, char b, map<char, Tree*>&mp)
{
    int length = 0;
    Tree *first = mp[a];
    char target = mp[b]->val;
    queue<Tree*>q;
    q.push(first);
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            Tree* temp = q.front();
            q.pop();
            if(temp->val == target)
                return length;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        length++;
    }
    return -1;
}

void clear(map<char, Tree*>& mp)
{
    for(auto it = mp.begin(); it != mp.end(); ++it)
        delete it->second;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        if(!n && !m)
            break;
        map<char, Tree*> mp;
        for(int i = 0; i < n; ++i)
        {
            char a, b , c;
            cin >> a >> b >> c;
            Tree *parent, *left, *right;
            if(mp.count(a) == 0)
            {
                parent = new Tree(a);
                mp.insert({a, parent});
            }
            else
            {
                parent = mp[a];
            }

            if(mp.count(b) == 0)
            {
                left = new Tree(b);
                mp.insert({b, left});
            }
            else
            {
                left = mp[b];
            }

            if(mp.count(c) == 0)
            {
                right = new Tree(c);
                mp.insert({c, right});
            }
            else
            {
                right = mp[c];
            }
            parent->left = left;
            parent->right = right;
        }
        for(int i = 0; i < m; ++i)
        {
            char a, b;
            cin >> a >> b;
            int len1 = solve(a, b, mp);
            int len2 = solve(b, a, mp);
            if(len1 == -1 && len2 == -1)
            {
                cout << '-' << endl;
                continue;
            }
            if(len1 > 0)
            {
                string ans = "child";
                if(len1 > 1)
                    ans = "grand" + ans;
                for(int j = 2; j < len1; ++j)
                    ans = "great-" + ans;
                cout << ans << endl;
            }
            else if(len2 > 0)
            {
                string ans = "parent";
                if(len2 > 1)
                    ans = "grand" + ans;
                for(int j = 2; j < len2; ++j)
                    ans = "great-" + ans;
                cout << ans << endl;
            }
        }
        clear(mp);
    }
}