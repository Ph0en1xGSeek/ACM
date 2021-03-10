#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    int ca, x, y, r;
    cin >> ca;
    while(ca--)
    {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> r;
        if((x-r >= a && y-r >= b) && (x+r <= c && y+r <= d))
            cout << "Just do it" << endl;
        else
            cout << "Don't get close to it" << endl;
    }
    return 0;
}
