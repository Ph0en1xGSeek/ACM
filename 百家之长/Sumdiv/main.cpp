#include <iostream>
#define mod 9901
#define ll long long

using namespace std;

int p[10000];
int n[10000];
int divide(int a, int b)//分解质因数
{
    int i, k = 0;
    for(i = 2; i*i <= a;)
    {
        if(a % i == 0)
        {
            p[k] = i;
            n[k] = 0;

            while(a % i == 0)
            {
                n[k]++;
                a /= i;
            }
            k++;
        }
        if(i == 2)//奇偶法，不这么做也行 太慢
            i++;
        else
            i += 2;
    }
    if(a != 1)
    {
        p[k] = a;
        n[k++] = 1;
    }
    return k;
}

ll power(ll p, ll n)//快速幂
{
    ll ret = 1;
    while(n)
    {
        if(n & 1)
            ret = (ret * p) % mod;
        n /= 2;
        p = p * p % mod;
    }
    return ret;
}

ll sum(ll p, ll n)
{
    if(n == 0)
        return 1;
    if(n & 1)
        return (sum(p, n/2)*(1+power(p, n/2+1))) % mod;
    else
        return (sum(p, n/2-1)*(1+power(p, n/2+1))+power(p, n/2)) % mod;
}

int main()
{
    int A, B;

    while(cin >> A >> B)
    {
        int k = divide(A, B);
        int ans = 1;
        for(int i = 0; i < k; i++)
            ans = (ans*(sum(p[i], n[i]*B)%mod))%mod;
        cout << ans << endl;
    }
    return 0;
}
