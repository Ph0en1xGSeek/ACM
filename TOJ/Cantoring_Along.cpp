#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int order[13] = {1,3,9,27,81,243,729,2187,6561,19683,
                    59049,177147,531441};
    int n, flag;
    while(scanf("%d", &n) != EOF)
    {
        for(int j = 0; j < order[n]; j++)
        {
            flag = 0;
            for(int i = n-1; i >= 0; i--)
            {
                if((j/order[i]) & 1)
                {
                    printf(" ");
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                printf("-");
        }
        printf("\n");

    }

    return 0;
}
