/**�������������nlogn�� ά��һ��vector
ʼ���������ֶ����滻���治С���Լ��ĵ�һ����
ͬʱҲ�ܻ����iλ��β��������������г���dp**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 110000

using namespace std;


int n,val[N];
int arr[N];
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

int main(){

    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        vt.clear();
        memset(arr, 0, sizeof(arr));
        scanf("%d", &n);
        for(int i=0;i<n;i++)
            scanf("%d",&val[i]);
        int tmp;
        for(int i=0;i<n;i++)
        {
            tmp = binarySearch(val[i]);
            if(tmp >= (int)vt.size())
            {
                vt.push_back(val[i]);
                arr[i] = (int)vt.size();
            }
            else
            {
                vt[tmp]=val[i];
                arr[i] = tmp+1;
            }
            ///tmp�ǵ�һ����С��vali��λ��
            ///�滻����������ά���������������
        }
         printf("%d", arr[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", arr[i]);
        printf("\n");
    }
    return 0;
}
