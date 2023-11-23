#include <iostream>
#include <stack>
#include <queue>
#include <map>
using namespace std;

map<int, char> m;

void solveD(queue<char>& q, double decimal, int k)
{
    int len = 3;
    while(len-- && decimal != 0)
    {
        decimal *= k;
        int temp = decimal >= 1 ? decimal/1 : 0;
        q.push(m[temp]);
        decimal -= temp;
    }
}

void solveI(stack<char>& s, int integer, int k)
{
    while(integer != 0)
    {
        int tail = integer % k;
        integer /= k;
        s.push(m[tail]);
    }
}

int main()
{
    int t; 
    cin >> t;
    m[1] = '1'; m[2] = '2'; m[3] = '3'; m[4] = '4'; 
    m[5] = '5'; m[6] = '6'; m[7] = '7'; m[8] = '8'; 
    m[9] = '9'; m[10] = 'A'; m[11] = 'B'; m[12] = 'C'; 
    m[13] = 'D'; m[14] = 'E'; m[15] = 'F'; m[0] = '0'; 
    while(t--)
    {
        double num;
        int k;
        cin >> num >> k;
        int integer = num / 1;
        double decimal = num - integer;
        queue<char> q;
        stack<char> s;
        solveD(q, decimal, k);
        solveI(s, integer, k);
        while(!s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << '.';
        int i = 3;
        while(!q.empty())
        {
            i--;
            cout << q.front();
            q.pop();
        }
        while(i--)
            cout << '0';
        cout << endl;
    }
    return 0;
}