#include <iostream>
using namespace std;

int main()
{
    int times;
    cin >> times;
    while(times--)
    {
        int a[2][3];
        for(int i = 0 ; i < 2; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                cin >> a[i][j];
            }
        }
        //int *p = a;
        int *p = &a[0][0];
        int ans[3][2];
        ans[0][0] = *(p+2);
        ans[0][1] = *(p+5);
        ans[1][0] = *(p+1);
        ans[1][1] = *(p+4);
        ans[2][0] = *(p+0);
        ans[2][1] = *(p+3);
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}