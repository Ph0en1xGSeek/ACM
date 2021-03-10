#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
#define N 10000001
typedef long long LL;
int len;
char str[N];

int main()
{


    int i=1;
    while(scanf("%s", str) != EOF)
    {

        int d = 10001;
        int ans = 0;
        for(int j = 0; str[j]; j++)
            ans = (ans * 10 + (str[j] - '0') % d) % d;


        if( ans == 0)
            printf("Case #%d: YES\n", i++);
        else
            printf("Case #%d: NO\n", i++);
    }
    return 0;
}
