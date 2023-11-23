#include <iostream>
#include <algorithm>
using namespace std;

struct SPoint
{
    int x, y;
};

struct SRect
{
    SPoint p1, p2;
};

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        SRect rect1, rect2;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        rect1.p1.x = min(x1, x2);
        rect1.p1.y = min(y1, y2);
        rect1.p2.x = max(x1, x2);
        rect1.p2.y = max(y1, y2);
        
        rect2.p1.x = min(x3, x4);
        rect2.p1.y = min(y3, y4);
        rect2.p2.x = max(x3, x4);
        rect2.p2.y = max(y3, y4);

        if (rect2.p1.x > rect1.p2.x || rect2.p2.x < rect1.p1.x || rect1.p1.y > rect2.p2.y || rect1.p2.y < rect2.p1.y)
            cout << "not overlapped" << endl;
        else
            cout << "overlapped" << endl;
    }
    return 0;
}
