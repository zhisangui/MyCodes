#include <iostream>
using namespace std;

int main()
{
    char a[100],b[100],c[100];
    int times, start1, start2, start3, end1, end2, end3;
    cin >> times;
    while(times--)
    {
        cin >> a >> b >> c
            >> start1 >> end1 
            >> start2 >> end2
            >> start3 >> end3;
        int len = end1 + end2 + end3 - start1 - start2 - start3 + 3;
        char* ans = new char[len + 1];
        int num = 0;
        for(int i = start1 - 1; i < end1; ++i)
            *(ans + num++) = *(a+i);

        for(int i = start2 - 1; i < end2; ++i)
            *(ans + num++) = *(b+i);
            
        for(int i = start3 - 1; i < end3; ++i)
            *(ans + num++) = *(c+i);  
        *(ans + num++) = 0;
        cout << ans << endl;
        delete []ans;
    }
    return 0;
}