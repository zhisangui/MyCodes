#include<iostream>
#include<iomanip>
using namespace std;
class Date {
    int year, month, day;
public:
    Date();                             // 缺省构造函数，给year、month、day分别赋值为1900、1、1
    Date(int y, int m, int d);          // 带参构造函数，给year、month、day分别赋参数的值
    int getYear();                      // 返回当前日期的年份
    int getMonth();                     // 返回当前日期的月份
    int getDay();                       // 返回当前日期的日
    void setDate(int y, int m, int d);  // 按参数重设日期的值
    void print();                       
    void addOneDay();                   // 在当前日期上加一天
    bool isyear(int year);
};

Date::Date()
{
    year = 1900, month = 1, day = 1;
}

Date::Date(int y, int m, int d)
{
    year = y, month = m, day = d;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::setDate(int y, int m, int d)
{
    year = y, month = m, day = d;
}

void Date::print()
{
    cout << setfill('0') << setw(2) 
    << year << '/' 
    << setfill('0') << setw(2)
    << month << '/'
    << setfill('0') << setw(2)
    << day << endl;
}

bool Date::isyear(int year)
{
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0; 
}

void Date::addOneDay()
{
    int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(isyear(year))
        months[2] = 29;
    if(++day > months[month])
    {
        day = 1;
        month++;
        if(month > 12)
        {
            month = 1;
            year++;
        }
    }
}

int main()
{
    int times, y, m, d;
    cin >> times;
    for(int i = 1; i <= times; ++i)
    {
        cin >> y >> m >> d;
        if(i % 2 == 1)
        {
            Date today(y,m,d);
            cout << "Today is ";
            today.print();
            today.addOneDay();
            cout << "Tomorrow is ";
            today.print();
        }
        else
        {
            Date today;
            today.setDate(y,m,d);
            cout << "Today is ";
            today.print();
            today.addOneDay();
            cout << "Tomorrow is ";
            today.print();
        }
    }
    return 0;
}