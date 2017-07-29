#include <iostream>
#include <cstdio>

using namespace std;

int father[100010];
int rank[100010];

void init(int q)
{
   for(int i = 1; i <= q ; i++)
   {
       father[i] = -1;
       rank[i] = 0;
   }
}

int getFather(int n)
{
    if(father[n] == -1)
        return n;
    int t = father[n];
    father[n] = getFather(father[n]);
    rank[n] = (rank[n] + rank[t]) % 2;
    return father[n];
}

void unions(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);
    if(fa != fb)
    {
        father[fa] = fb;
        rank[fa] = (rank[a]+rank[b] + 1)%2;

    }

}

int main()
{
    int num, q, m;
    char ch;
    int a, b;
    scanf("%d", &num);
    while(num--)
    {
        scanf("%d%d", &q, &m);
        init(q);
        for(int i = 0; i < m; i++)
        {
            scanf("%c%d%d",&ch,&a,&b);
            if(ch == 'A')
            {
                if(getFather(a) != getFather(b))
                    printf("Not sure yet.\n");
                else
                {

                    if((rank[a] + rank[b]) % 2 == 0)
                        printf("In the same gang.\n");
                    else
                        printf("In different gangs.\n");
                }
            }
            else
            {
                unions(a, b);
            }
        }
    }
    return 0;
}
