#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr [105][105];
bool used[105];
int Link[105];
int record[105][2];
int n;

bool match(int u)///�������㷨
{
    for(int i = 1; i <= n; ++i)
    {
        if(!used[i] && arr[u][i])///���λ�û��������Ҷ����������
        {
            used[i] = true;
            if(Link[i] == -1 || match(Link[i]))
            {
                Link[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int cnt, ct;
    while(scanf("%d", &n) != EOF)
    {
        cnt = ct = 0;
        memset(Link, -1, sizeof(Link));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &arr[i][j]);
        for(int i = 1; i <= n; i++)
        {
            memset(used, 0, sizeof(used));
            if(match(i)) cnt++;
        }
        if(cnt >= n)
        {
            for(int i = 1; i <= n; i++)
            {
                int j;
                for(j = i; j <= n; j++)
                    if(Link[j] == i) break;
                if(i != j)
                {
                    record[ct][0] = i;
                    record[ct++][1] = j;
                    swap(Link[i], Link[j]);///ij�н�����j��ƥ��i�� j�б����i�У���Ҫ��ƥ�����Ҳ��ΪLink[i]
                }
            }
            printf("%d\n", ct);
            for(int i = 0; i < ct; i++)
                printf("C %d %d\n", record[i][0], record[i][1]);
        }
        else
            printf("-1\n");
    }
    return 0;
}
