#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    unsigned int n;
    int i;
    while(scanf("%u", &n) != EOF)
    {
        for(i = 0; n > 1; i++)
        {
            if(i&1) n = ceil(n*1.0/2.0);
            else    n = ceil(n*1.0/9.0);
        }
        if(i&1) printf("Stan wins.\n");
        else    printf("Ollie wins.\n");
    }
    return 0;
}
