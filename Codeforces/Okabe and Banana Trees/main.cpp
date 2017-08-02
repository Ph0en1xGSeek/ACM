#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {

    int m, b;
    while (scanf("%d%d", &m, &b) != EOF)
    {
        long long x;
        long long mx = 0;
        for(int y = 0; y <= b; y++)
        {
            x = (long long)m*b - m*y;
            long long tmp = x*(x+1)/2;
            tmp = (long long)(y+1)*tmp + (long long)(y+1)*y/2 * (x+1);
            if(tmp > mx)
            {
                mx = tmp;
            }
        }

        printf("%lld\n", mx);
    }
    return 0;
}