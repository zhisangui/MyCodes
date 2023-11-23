#include<iostream>
using namespace std;

void preOrder(int *tree, int num, int root)
{
    cout << tree[root] << ' ';
    if(root*2 <= num && tree[root*2])
        preOrder(tree, num, root*2);
    if(root*2+1 <= num && tree[root*2+1])
        preOrder(tree, num, root*2+1);
}   

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int num;
        cin >> num;
        int* tree = new int[num+1];
        for(int i = 1; i <= num; ++i)
            cin >> tree[i];
        preOrder(tree, num, 1);
        cout << endl;
    }
}