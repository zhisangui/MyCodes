#include<iostream>
using namespace std;

int main()
{
    const char* months[] = {"None","January", "February","March","April","May","June","July","August","September","October","November","December"};
    int times, month;
    cin >> times;
    while(times--)
    {
        cin >> month;
        if(month < 1 || month > 12)
            cout << "error" << endl;
        else
            cout << months[month] << endl;
    }
    return 0;
}