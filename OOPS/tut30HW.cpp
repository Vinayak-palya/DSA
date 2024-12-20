#include <iostream>
#include <math.h>
using namespace std;

class point
{
    int x, y;
    friend int calc(point, point);

public:
    point(int, int);
};
point ::point(int a, int b)
{
    x = a;
    y = b;
}
int calc(point p1, point p2)
{
    int hor = (p1.x - p2.x) * (p1.x - p2.x);
    int ver = (p1.y - p2.y) * (p1.y - p2.y);
    int ans = sqrt(hor + ver);
    return ans;
}
int main()
{

    point p1(3, 4), p2(0, 0);
    int dis = calc(p1, p2);
    cout << "The distance between the two points are: " << dis << "\n";
    return 0;
}
// if you are declaring a member function than  you should use that function with the hlp of dot operator or make it a friend function