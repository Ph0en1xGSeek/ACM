#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int x,y=0,odd;
    int l=0;
    int r=1e9;
    printf("%d %d\n",l,y);
    cout.flush();
    scanf("%d",&odd);
    while(l<r)
    {
        printf("%d %d\n",r,y);
        cout.flush();
        scanf("%d",&odd);
        int mid=(l+r)>>1;
        if(odd==0)
        {
            r=mid;
        }
        else
            l=mid+1;
        printf("%d %d\n",l,y);
        cout.flush();
        scanf("%d",&odd);
    }
    x=l;
    l=0;
    r=1e9;
    printf("%d %d\n",x,l);
    cout.flush();
    scanf("%d",&odd);
    while(l<r)
    {
        printf("%d %d\n",x,r);
        cout.flush();
        scanf("%d",&odd);
        int mid=(l+r)>>1;
        if(odd==0)
            r=mid;
        else
            l=mid+1;
        printf("%d %d\n",x,l);
        cout.flush();
        scanf("%d",&odd);
    }
    y=l;
    printf("A %d %d\n",x,y);
    cout.flush();
    return 0;
}
