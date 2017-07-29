#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 9999999

using namespace std;

int main()
{
    int n, tmp;
    int mi, mx;
    while(scanf("%d", &n) != EOF)
    {
        mi = INF;
        mx = -INF;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if(tmp < mi)
                mi = tmp;
            else if(tmp > mx)
                mx = tmp;
        }
        printf("%d %d\n", mx, mi);
    }
    return 0;
}
