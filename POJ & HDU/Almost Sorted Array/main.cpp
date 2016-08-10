#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 110000

using namespace std;

int n,val[N];
vector<int> vt, vt2;

int binarySearch(int x)
{
    int left=0,right=vt.size()-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(vt[mid] < x)
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int binarySearch2(int x)
{
    int left=0,right=vt2.size()-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(vt2[mid] > x)
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int main(){

    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        vt.clear();
        vt2.clear();
        scanf("%d", &n);
        for(int i=0;i<n;i++)
            scanf("%d",&val[i]);
        int tmp, tmp2;
        for(int i=0;i<n;i++)
        {
            tmp = binarySearch(val[i]+1);
            tmp2 = binarySearch2(val[i]-1);
            if(tmp >= (int)vt.size())
                vt.push_back(val[i]);
            else
                vt[tmp]=val[i];
            if(tmp2 >= (int)vt2.size())
                vt2.push_back(val[i]);
            else
                vt2[tmp2]=val[i];
        }
        if(vt.size() >= n-1 || vt2.size() >= n-1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
