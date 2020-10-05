/**最大上升子序列nlogn版 维护一个vector
始终用新数字二分替换里面不小于自己的第一个数
同时也能获得已i位结尾的最大上升子序列长度dp**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 110000

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
    int num, val[100000];
    while(~scanf("%d", &num))
    {
        vt.clear();
        for(int i = 0; i < num; i++)
            scanf("%d", &val[i]);
        for(int i=0;i<num;i++)
        {
            int tmp = binarySearch(val[i]);
            if(tmp >= (int)vt.size())
            {
                vt.push_back(val[i]);
            }
            else
            {
                vt[tmp]=val[i];
            }
            ///tmp是第一个不小于vali的位置
            ///替换它或加在最后维护最大上升子序列
        }
        printf("%d\n", vt.size());
    }
    return 0;
}
