#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 100000000

using namespace std;

int dp[100001];//����Ϊi+1����������С�Ľ�β

int main()
{
    int tail = 0;//��󳤶�
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
                    low = mid + 1;//low���Ϊ��С��n�ĵ�һ����
            }
            if(low >= tail)
                tail++;
            dp[low] = n;
        }
        printf("%d\n", tail);
    }

    return 0;
}
