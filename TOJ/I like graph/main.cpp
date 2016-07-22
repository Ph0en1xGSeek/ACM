#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 100000000

using namespace std;

int dp[100001];//长度为i+1的子序列最小的结尾

int main()
{
    int tail = 0;//最大长度
    int num, n;
    while(scanf("%d", &num) != EOF)
    {
        tail = 0;
        while(num--)
        {
            scanf("%d", &n);
            int low = 0, high = tail-1;
            while(low <= high)
            {
                int mid = (low + high) >> 1;
                if(dp[mid] >= n)
                    high = mid - 1;
                else
                    low = mid + 1;//low最后为不小于n的第一个数
            }
            if(low >= tail)
                tail++;
            dp[low] = n;
        }
        printf("%d\n", tail);
    }

    return 0;
}
