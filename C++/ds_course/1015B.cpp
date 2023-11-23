#include <iostream>
using namespace std;

void search(int* num, int n, int* nmax, int* nmaxindex)
{
    *nmax = num[0];
    for (int i = 1; i < n; ++i)
    {
        if (*(num + i) > *nmax)
        {
            *nmax = num[i];
            *nmaxindex = i;
        }
    }
}

void input(int* num, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cin >> *(num + i);
    }
}

int main()
{
    int times, index, max;
    cin >> times;
    while (times--)
    {
        int n, *nmax = &max, *nmaxindex = &index;
        cin >> n;
        int* array = new int[n];
        input(array, n);
        index = 0;
        search(array, n, nmax, nmaxindex);
        cout << *nmax << ' ' << *nmaxindex << endl;
        delete []array;
    }
    return 0;
}