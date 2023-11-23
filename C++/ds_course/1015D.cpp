#include <iostream>
using namespace std;

struct SPoint
{
    int x, y;
};

struct SLine
{
    SPoint p1, p2;
};

typedef SPoint Vector;

void direction(const SLine &ab, const SPoint &c)
{
    Vector a, b;
    a.x = ab.p2.x - ab.p1.x;
    a.y = ab.p2.y - ab.p1.y;
    b.x = c.x - ab.p1.x;
    b.y = c.y - ab.p1.y;
    int ans = a.x * b.y - a.y * b.x;
    if(ans == 0)
        cout << "intersect" << endl;
    else if(ans > 0)
        cout << "anti clockwise" << endl;
    else
        cout << "clockwise" << endl;
}   

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int x1, y1, x2, y2, x, y;
        cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
        SPoint p;
        p.x = x, p.y = y;
        SLine L;
        L.p1.x = x1, L.p1.y = y1;
        L.p2.x = x2, L.p2.y = y2;
        direction(L, p);
    }

}