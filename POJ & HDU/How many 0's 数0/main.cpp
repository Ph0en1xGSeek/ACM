#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long b[12] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000};

long long count(long long n)
{
    long long left, m, sum = 0;
    for ( int i = 1; i < 12; i++ )
    {
        left = n / b[i] - 1;
        sum += left * b[i-1];//4363里十位上点的0十个十个出现了42次 还有一次不知是否完整10个
        m = (n % b[i] - n % b[i-1]) / b[i-1];
        if ( m > 0 )
            sum += b[i-1];//完整出现了
        else if (m == 0)
            sum += n % b[i-1] + 1;//不完整出现了多少次
        if (n < b[i])
            break;
    }
    return sum;
}

int main()
{
    long long m, n;
    while ( cin >> m >> n && m >= 0)
        cout << count(n)-count(m-1) << endl;
    return 0;
}
