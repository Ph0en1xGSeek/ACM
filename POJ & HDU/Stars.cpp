#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>

using namespace std;
int n;
int c[32005];
int val[32005];//��¼ÿ���ȼ�����Ŀ

void update(int x, int num)
{
    while(x <= 32005)
    {
        c[x] += num;
        x += x&(-x);
    }
}

int getsum(int x)//ǰ׺�ͣ�
{
    int ans = 0;
    while(x > 0)
    {
        ans += c[x];
        x -= x&(-x);
    }
    return ans;
}

int main()
{

    int x, y;
    while(scanf("%d", &n) != EOF)
    {
        memset(c, 0, sizeof(c));
        memset(val, 0, sizeof(val));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            x++; //��ֹ x=0 updateʱ����ѭ��
            val[getsum(x)]++;
            update(x, 1);
        }
        for(int i = 0; i < n; i++)
        {
            printf("%d\n", val[i]);
        }
    }

    return 0;
}
