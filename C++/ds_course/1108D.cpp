#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
    double x, y;
public:
    Point():x(x),y(y)
    {
        cout << "Constructor." << endl;
    }

    Point(double x_value, double y_value):x(x_value),y(y_value)
    {
        cout << "Constructor." << endl;
    }

    Point(const Point& p):x(p.x),y(p.y)
    {
        cout << "Constructor." << endl;
    }

    void setXY(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    ~Point()
    {
        cout << "Distructor." << endl;
    }     

    double getDisTo(const Point &p)
    {
        return sqrt((x-p.x) * (x-p.x) + (y-p.y) * (y-p.y));
    }                 
};

int main()
{
    int times, num;
    cin >> times;
    while(times--)
    {
        cin >> num;
        Point points[num];
        for(int i = 0; i < num; ++i)
        {
            double x, y;
            cin >> x >> y;
            points[i].setXY(x, y);
        }
        double maxn = 0;
        int left, right;
        for(int i = 0; i < num-1; ++i)
        {
            for(int j = i + 1; j < num; ++j)
            {
                double distance = points[i].getDisTo(points[j]);
                if(distance > maxn)
                {
                    maxn = distance;
                    left = i, right = j;
                }
            }
        }
        cout << "The longeset distance is " 
        << fixed << setprecision(2)
        << maxn << ",between p[" << left
        << "] and p[" << right << "]." << endl;
    }
}