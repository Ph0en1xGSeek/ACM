#include <stdio.h>
#include <algorithm>
#define Max 4001

using namespace std;

int A[Max];
int B[Max];
int C[Max];
int D[Max];
int E[Max*Max];
int num;
int ans = 0;
int siz;

int bsearch(int* A, int v)
{
    int x = 0, y = siz - 1;
    int m,t, cnt = 0;
    while(x <= y)
    {
        m = x + (y - x) / 2;
        if(A[m] == v)
            break;
        else if(A[m] > v)
            y = m - 1;
        else
            x = m + 1;
    }
   if (v == A[m])
    {
        ++cnt;
        t = m;
        while (t > 0 && v == A[--t]) ++cnt;
         while (m < siz-1 && v == A[++m]) ++cnt;
     }
     return cnt;
}

int main()
{

    scanf("%d", &num);

        for(int i = 0; i < num; i++)
        {
            scanf("%d%d%d%d", &A[i] , &B[i] , &C[i] , &D[i]) ;
        }
        for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            E[i*num + j] = A[i] + B[j];

        sort(E, E+num*num);
        siz = num*num;
        for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
        {
            ans += bsearch(E,-(C[i] + D[j]));
        }

        printf("%d\n", ans);

    return 0;
}
