#include <stdio.h>
#include <iostream>

using namespace std;
int goal[1001];
int main()
{
    int num;
    int n;

    scanf("%d", &num);
    while(num--)
    {
        int above = 0;
        int total = 0;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &goal[i]);
            total += goal[i];
        }
        for(int j = 0; j < n; j++)
        {
            if(goal[j] * n > total)
                above++;
        }
        double race = (above * 100.0) / (double)n ;
        printf("%.3f", race);
        cout<< '%' << endl;
    }

    return 0;
}
