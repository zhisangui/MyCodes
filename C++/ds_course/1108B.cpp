#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int times;
    cin >> times;
    while(times--)
    {
        int num, index;
        cin >> num;
        int students[num];
        for(int i = 0; i < num; ++i)
        {
            cin >> students[i];
        }
        cin >> index;
        int *ptr = &students[num/2];
        --ptr;
        cout << *ptr << ' ';
        ++++ptr;
        cout << *ptr << endl;
        int flag = 0;
        if((num/2+1 - (index-1) > 0))
            flag = 1;
        else 
            flag = 0;
        for(int i = 0; i < abs((num/2+1 - (index-1) )); ++i)
        {
            if(flag)
                --ptr;
            else
                ++ptr;
        }
        cout << *ptr << endl;
    }
    return 0;
}