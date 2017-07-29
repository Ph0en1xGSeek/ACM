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
}

int main()
{
    long long num;
    while(cin >> num, num)
    {
        cout << multi(num, num, 2006) << endl;
    }
    return 0;
}
