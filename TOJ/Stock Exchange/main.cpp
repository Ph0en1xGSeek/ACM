/**�������������nlogn�� ά��һ��vector
ʼ���������ֶ����滻���治С���Լ��ĵ�һ����
ͬʱҲ�ܻ����iλ��β��������������г���dp**/

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
            ///tmp�ǵ�һ����С��vali��λ��
            ///�滻����������ά���������������
        }
        printf("%d\n", vt.size());
    }
    return 0;
}
