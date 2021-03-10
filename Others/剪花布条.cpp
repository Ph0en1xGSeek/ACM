#include<stdio.h>
#include <cstring>
using namespace std;

char s[1011],t[1011];
int nex[1011];

int n,m;

int getnext()
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
    int ans=0;
    getnext();
    int i=0,j=0;
    while(i<n)
    {
        while(j!=-1&&s[i]!=t[j])
            j=nex[j];
        i++;
        j++;
        if(j>=m)///(0~m-1)
        {
            ans++;
            j = 0;
            //j=nex[j];
        }
    }
    return ans;
}

int main()
{

    while(scanf("%s",s) && s[0] != '#')
    {
        scanf("%s",t);
        m = strlen(t);
        n = strlen(s);
        printf("%d\n", kmp());
    }
    return 0;
}
