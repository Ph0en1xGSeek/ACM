#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#define MAXN 105
#define INF 1000000000
using namespace std;

struct node
{
    int pos;
    char x[12];
}tmp;

int top, found, st[400000], mi;
int d[] = {-1, -3, 1, 3};
char as[] = "lurd";
bool mov[][4] = {{0,0,1,1}, {1,0,1,1}, {1,0,0,1}, {0,1,1,1}, {1,1,1,1}, {1,1,0,1}, {0,1,1,0}, {1,1,1,0}, {1,1,0,0}};//�������d���ߵķ�ʽΪ1

int h(node &t)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            int k = i * 3 + j;
            if(t.x[k] == 'x')
                continue;
            sum += abs(i - (t.x[k] - '1') / 3) + abs(j - (t.x[k] - '1') % 3);// /3Ϊ�У�%3Ϊ��
        }//��λ���ϵ�������ԭ�����ڵ�λ�õ������پ���
    return sum;
}

void output()
{
    for(int i = 1;i <= top; i++)
        printf("%c", as[st[i]]);
    printf("\n");
}

void dfs(int p, int dp, int maxdp)
{
    int f = h(tmp);
    int i, t;
    if(mi > f)
        mi = f;
    if(f + dp > maxdp || found)
        return;
    if(f == 0)
    {
        output();
        found = 1;
        return;
    }
    for(i = 0;i < 4; i++)
    {
        if(mov[p][i] == 0)
            continue;
        t = d[i] + p;
        if(top > 0 && d[st[top]] + d[i] == 0)
            continue;  //һ����Ҫ�ļ�֦�����֮ǰ��һ�������ڵ�һ�����෴�ģ��������������ù�������������
        swap(tmp.x[t], tmp.x[p]);
        st[++top] = i;
        dfs(t, dp + 1, maxdp);
        top--;
        swap(tmp.x[t], tmp.x[p]);
    }
}

void IDA()
{
    int maxdp = h(tmp);//��ʼΪ��״̬��hֵ
    found = 0;
    while(found == 0)
    {
        mi = 0x7fffffff; //mi��ʾ�ڵ�ǰ��hֵ�����������ѵ�������λ�ã���hֵ��С��λ��
        top = 0;
        dfs(tmp.pos, 0, maxdp);
        maxdp += mi; //��������ѵ��ͽ�mi����ȥ
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        scanf("%s", &tmp.x[i]);
        if(tmp.x[i] == 'x')
            tmp.pos = i;
    }
    IDA();
    return 0;
}
