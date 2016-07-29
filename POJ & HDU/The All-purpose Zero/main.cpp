#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vt;

int binarySearch(int x)
{
    int left=0,right=vt.size()-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(vt[mid]<x)
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int main()
{
    int ca, cnt, num, n;
    int cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        cnt = 0;
        vt.clear();
        scanf("%d", &n);
        int tmp;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &num);
            if(num == 0)
                cnt++;
            else
            {
                tmp = binarySearch(num-cnt);
                if(tmp >= (int)vt.size())
                {
                    vt.push_back(num-cnt);
                }
                else
                {
                    vt[tmp] = num-cnt;
                }
            }

            ///tmp是第一个不小于vali的位置
            ///替换它或加在最后维护最大上升子序列
        }
        printf("Case #%d: %d\n", cc++, vt.size() + cnt);
    }
    return 0;
}
