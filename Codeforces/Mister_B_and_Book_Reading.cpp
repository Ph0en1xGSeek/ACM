#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {
    int c, v0, v1, a, l;
    int cnt;
    int tmp;

    while (scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l) != EOF)
    {
        cnt = 1;
        tmp = v0;
        while (tmp < c)
        {
            tmp -= l;
            v0 += a;
            v0 = min(v0, v1);
            tmp += v0;
            tmp = min(c, tmp);
            cnt++;
        }

        printf("%d\n", cnt);

    }
    return 0;
}