#include <stdio.h>
#include <cstring>
using namespace std;

char s[1000005],t[10005];
int nex[10005];

int n,m;

void getnext()
{
    int i = 0;
    int j = -1;
    nex[0] = -1;
    while(i < m )
    {
        if(j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            nex[i] = j;
        }
        else
            j = nex[j];
    }
}

int kmp()
{
    int ans = 0;
    getnext();
    int i = 0, j = 0;
    while(i < n)
    {
        while(j != -1 && s[i] != t[j])
            j = nex[j];
        i++;
        j++;
        if(j >= m)
        {
            ans++;
            j = nex[j];
        }
    }
    return ans;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%s",t);
        scanf("%s",s);
        m = strlen(t);
        n = strlen(s);
        printf("%d\n", kmp());
    }
    return 0;
}
