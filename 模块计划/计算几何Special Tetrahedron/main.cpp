#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 205
#define square(x) ((x)*(x))

using namespace std;

struct node
{
    int x, y, z;
    node(){}
    node(int xx, int yy, int zz):x(xx), y(yy), z(zz){}
}arr[M];

pair<int, int> vetex[M];
int cnt;

node xmulti(node a, node b)///叉积
{
    return node(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

int dist(node a, node b)///距离的平方
{
    return square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z);
}

int dmulti(node a, node b)///点积
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

node vct(node a, node b)///向量ab
{
    return node(b.x-a.x, b.y-a.y, b.z-a.z);
}

node normal(node a, node b, node c)///法向量
{
    return xmulti(vct(a, b), vct(a, c));
}

bool onPlane(node a, node b, node c, node d)///共面
{
    return dmulti(normal(a, b, c), vct(a, d)) == 0;
}

int main()
{
    int ca, cc = 1, num;
    int sum1, sum2;///六条边相等 非6条相等
    scanf("%d", &ca);
    while(ca--)
    {
        sum1 = sum2 = 0;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
            scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].z);
        for(int i = 0; i < num-1; i++)
        {
            for(int j = i+1; j < num; j++)
            {
                cnt = 0;
                for(int k = 0; k < num; k++)///枚举不属于四条边的边
                {
                    if(k == i || k == j) continue;
                    int tmp = dist(arr[i], arr[k]);
                    if(tmp == dist(arr[j], arr[k]))
                        vetex[cnt].first = tmp, vetex[cnt++].second = k;
                }
                for(int k1 = 0; k1 < cnt-1; k1++)
                {
                    for(int k2 = k1+1; k2 < cnt; k2++)
                    {
                        if(vetex[k1].first != vetex[k2].first) continue;
                        if(onPlane(arr[i], arr[j], arr[vetex[k1].second], arr[vetex[k2].second])) continue;
                        int tmp = dist(arr[vetex[k1].second], arr[vetex[k2].second]);
                        if(tmp == dist(arr[i], arr[j]) && tmp == vetex[k1].first) sum1++;
                        else sum2++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", cc++, sum1/6+sum2/2);
    }
    return 0;
}
