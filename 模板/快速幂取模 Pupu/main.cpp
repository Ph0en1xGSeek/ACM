#include <iostream>

using namespace std;

long long multi(long long a, long long b, long long mod)
{
    long long ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret = (ret*a)%mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}//pow(a, b) mod m

int main()
{
    long long a;
    while(cin >> a && a)
    {
        long long ans = 0;
        if(a > 0)
            ans = (multi(2, a-1, a)+1)%a;
        cout << ans << endl;
    }

    return 0;
}
