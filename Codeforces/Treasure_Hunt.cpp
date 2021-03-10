#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main() {

    int x1, y1, x2, y2;
    int x, y;
    bool flag;
    while (scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y) != EOF)
    {
        flag = true;
        int tmpx = abs(x1-x2);
        int tmpy = abs(y1-y2);
        if(tmpx % x != 0)
            flag = false;
        else if(tmpy % y != 0)
            flag = false;
        else
        {
            tmpx /= x;
            tmpy /= y;
            if(abs(tmpx-tmpy) % 2 != 0)
                flag = false;
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}