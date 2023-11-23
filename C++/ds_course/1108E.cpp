#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void solve(char op)
{   
    int num;
    cin >> num;
    if(op == 'I')
    {
        int *array = new int[num];
        int sum = 0;
        for(int i = 0; i < num; ++i)
        {
            cin >> *(array+i);
            sum += *(array+i);
        }
        cout << sum / num << endl;
        delete []array;
    }
    else if(op == 'C')
    {
        char *array = new char[num];
        char c = 0;
        for(int i = 0; i < num; ++i)
        {
            cin >> *(array+i);
            c = max(c, *(array + i));
        }
        cout << c << endl;
        delete []array;
    }
    else
    {
        double *array = new double[num];
        double d;
        for(int i = 0; i < num; ++i)
        {
            cin >> *(array+i);
            if(i == 0)
                d = *(array+i);
            else
                d = min(d, *(array + i));
        }
        cout << d << endl;
        delete []array;
    }
}

int main()
{
    int times;
    cin >> times;
    while(times--)
    {
        char op;
        cin >> op;
        solve(op);
    }
    return 0;
}