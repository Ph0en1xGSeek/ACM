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

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}


int main()
{
    int a, b, x, y;
    cin >> a >> b;
    int ans = exgcd(a, b, x, y);
    cout << x << 'x' << a << '+' << y << 'x' << b << '=' << "gcd("
    << a << ',' << b << ") = " << ans << endl;
    return 0;
}
