#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int n;
    queue<char> Type;
    int A = 0, B = 0, C = 0, a = 0, b = 0, c = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        char op;
        cin >> op;
        Type.push(op);
    }
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        switch (Type.front())
        {
        case 'A':
            A += num;
            a++;
            break;
        case 'B':
            B += num;
            b++;
            break;
        case 'C':
            C += num;
            c++;
            break;
        default:
            break;
        }
        Type.pop();
    }
    cout << A / a << endl
        << B / b << endl
        << C / c;
    return 0;
}