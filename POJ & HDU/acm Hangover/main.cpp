#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double arr[300] = {0.0, 0.5};
    for(int i = 2; i < 300; i++)
    {
        arr[i] = arr[i - 1] + 1.0 / (i + 1.0);
    }
    double len;
    while(scanf("%lf", &len) && len != 0.00)
    {
        for(int i = 1; i < 300; i++)
        {
            if(arr[i] >= len)
            {
                printf("%d card(s)\n", i);
                break;
            }
        }
    }
    return 0;
}
