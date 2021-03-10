#include <iostream>

using namespace std;
int exgcd(int a, int b, int& x, int& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ret = exgcd(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}

int main()
{
    int ca;
    cin >> ca;
    int n, b, x, y;
    while(ca--)
    {
        cin >> n >> b;
        exgcd(b, 9973, x, y);
        x *= n;
        x = x % 9973;
        x = ((x % 9973)+9973) % 9973;
        cout << x << endl;
    }

    return 0;
}
