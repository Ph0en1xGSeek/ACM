#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int div[1000002];

int main()
{
    int num;
    int d, n;
    int ca;
    int sum;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(div, 0, sizeof(div));
        sum = 0;
        scanf("%d%d", &d, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            sum = (sum+num) % d;
            div[sum]++;
        }
        long long counts = 0;
        div[0]++;
        for(int i = 0; i < d; i++)
        {
            if(div[i] >= 2)
                counts = counts + (long long)(div[i] - 1)*(div[i])/2;
        }
        cout << counts << endl;
    }
	return 0;
}
