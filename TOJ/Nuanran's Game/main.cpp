#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    int x, y, z, n;
    while(scanf("%d%d%d%d", &x, &y, &z, &n) != EOF)
    {
        for(int i = 0; i < 201; i++)
            for(int j = 0; j < 201; j++)
                for(int k = 0; k < 201; k++)
                {
                    if(x*i + y*j - z*k == n)
                    {
                        printf("%d %d %d\n", i, j, k);
                        goto end;
                    }

                }
        printf("-1\n");
        end:;

    }
    return 0;
}
