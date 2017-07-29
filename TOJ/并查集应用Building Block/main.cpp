#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 333333

using namespace std;

int father[M];
int num[M];///ÿ���ж���
int under[M];

int getFather(int x)
{
    if(father[x] == -1)
        return x;
    int tmp = getFather(father[x]);
    under[x] += under[father[x]];///ÿ��getfatherʱ�Ż��������������ж���
    return (father[x] = tmp);
}

void unions(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);
    if(fa != fb)
    {
        under[fa] = num[fb];///a���ڶѵ������һ������Ϊb�Ѹ�����������underΪ0
        ///ע��a֮�ϵĻ�û�и��£���Ȼ��֮ǰ������ֱ��getFatherʱ�Ż����
        ///�ݹ�Ѹ��ڵ��under����
        num[fb] += num[fa];///b���ڶѸ�������a���ڶ�
        father[fa] = fb;///�ٲ�ѯa�ͻ��ѯ��b��һ��
    }
}

int main()
{
    int p, a, b;
    char ch;
    while(scanf("%d", &p) != EOF)
    {
        memset(father, -1, sizeof(father));
        for(int i = 0; i <= 300000; i++)
            num[i] = 1;
        memset(under, 0, sizeof(under));
        for(int i = 0; i < p; i++)
        {
            getchar();
            scanf("%c", &ch);
            if(ch == 'M')
            {
                scanf("%d%d", &a, &b);
                unions(a, b);
            }
            else
            {
                scanf("%d", &a);
                getFather(a);
                printf("%d\n", under[a]);
            }
        }
    }
    return 0;
}
