#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

long long a[105], b[105];

vector <long long>tp;

int main()
{
    long long x, y, l, r;
    int cnt1, cnt2;
    while(~scanf("%I64d%I64d%I64d%I64d", &x, &y, &l, &r))
    {
        tp.clear();
        cnt1 = cnt2 = 1;
        a[0] = b[0] = 1;
        while(r / x >= a[cnt1-1])
        {
            a[cnt1] = a[cnt1-1]*x;
            cnt1++;
        }
        while(r / y >= b[cnt2-1])
        {
            b[cnt2] = b[cnt2-1] * y;
            cnt2++;
        }
        for(int i = 0; i < cnt1; i++)
        {
            for(int j = 0; j < cnt2; j++)
            {
                long long tmp = a[i] + b[j];
                if(tmp >= l && tmp <= r)
                    tp.push_back(tmp);
            }
        }
        long long ans;
        if(tp.size() == 0)
        {
            ans = r-l+1;
        }
        else
        {
            sort(tp.begin(), tp.end());
            ans = max(tp[0] - l, r - tp[tp.size()-1]);
            for(int i = 1; i < tp.size(); i++)
                ans = max(ans, tp[i]-tp[i-1]-1);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
