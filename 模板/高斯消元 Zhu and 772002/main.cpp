#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define mod 1000000007

typedef long long ll;
using namespace std;
const int maxn = 2010;

typedef int Matrix[maxn][maxn];
int prime[maxn], vis[maxn];
Matrix A;

int gen_primes(int m)
{
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 2; i < m; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
            for (int j = i * i; j < m; j += i)
                vis[j] = 1;
        }
    }
    return cnt;
}

int rank1(Matrix A, int m, int n) ///���ؾ������
{
    int i = 0, j = 0, k , r, u;
    while (i < m && j < n)
    {
        r = i;
        for (k = i; k < m; k++) ///��ÿһ����Ԫ��������r
            if (A[k][j])
            {
                r = k;
                break;
            }
        if (A[r][j]) ///�ҵ�
        {
            if (r != i)
                for (k = 0; k <= n; k++)
                    swap(A[r][k], A[i][k]);///�н���
            for (u = i+1; u < m; u++)///�б任ʹ����Ԫ��Ϊ����Ψһ��0Ԫ��
                if (A[u][j])
                    for (k = i; k <= n; k++)
                        A[u][k] ^= A[i][k];
            i++;
        }
        j++;
    }
    return i;///�н����ж����У������Ⱦ��Ƕ���
}

long long multi(long long a, long long b)
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
    int m = gen_primes(2016);
    int t;
    scanf("%d", &t);
    for(int l=1;l<=t;l++)
    {
        int n, maxp = 0;;
        ll x;
        scanf("%d", &n);
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d", &x);
            for (int j = 0; j < m; j++)
                while (x % prime[j] == 0)
                {
                    maxp = max(maxp, j);
                    x /= prime[j];
                    A[j][i] ^= 1;
                }
        }
        int r = rank1(A, maxp+1, n);
        cout<<"Case #"<<l<<":"<<endl;
        printf("%I64d\n", (multi(2ll, (long long)(n-r)) - 1ll)%mod);
    }
    return 0;
}
