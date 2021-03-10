#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

string str;
map<string, int> m;

int main()
{
    int ca, num;
    int odd, even;
    scanf("%d", &ca);
    while(ca--)
    {
        m.clear();
        odd = even = 0;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            cin >> str;
            if(str.length() & 1)
                odd++;
            else
                even++;
            m[str]++;
        }
        long long fenzi = odd * even;
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            int tmp = it->second;
            if(tmp > 1)
            {
                fenzi += tmp * (tmp-1) / 2;
            }
        }

        if(fenzi == 0)
            printf("0/1\n");
        else
        {
            long long fenmu = num * (num-1) / 2;
            long long gcd = __gcd(fenzi, fenmu);
            printf("%I64d/%I64d\n", fenzi/gcd, fenmu/gcd);
        }
    }
    return 0;
}
