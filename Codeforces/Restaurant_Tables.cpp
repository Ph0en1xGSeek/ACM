#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {

    int n, a, b, tmp;
    int cnt;
    int half = 0;
    scanf("%d%d%d", &n, &a, &b);
    cnt = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if(tmp == 1)
        {
            if(a > 0) a--;
            else if(b > 0)
            {
                b--;
                half++;
            }
            else if(half > 0)
                half--;
            else
                cnt++;
        }
        else
        {
            if(b > 0) b--;
            else cnt+=2;
        }
    }
    printf("%d\n", cnt);
    return 0;
}