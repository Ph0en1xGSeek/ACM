/**异或和为零为必败态，想赢就制造必败态，也就是若异或和不为0
就选某个数，比其他数异或和大，拿走一些石子变成其他数的异或和就行，
有多少个这样的数 就有多少种赢法（后面的步骤都由对手的走法而定）**/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int num;
    int ans, tot;
    int arr[1005];
    while(scanf("%d", &num) && num)
    {
        tot = 0;
        ans = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
            tot ^= arr[i];
        }
        if(tot == 0)
            printf("0\n");
        else
        {
            for(int i = 0; i < num; i++)
            {
                if((tot ^ arr[i]) < arr[i])
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
