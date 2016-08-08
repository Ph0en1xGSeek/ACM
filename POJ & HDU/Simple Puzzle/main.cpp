#include<stdio.h>
#include<stdlib.h>
int num[90005], res[90005];
int sum;

void mergesort(int l, int r)///左闭右开
{
    int mid, i, j, tmp;
    if(r>l+1)
    {
        mid=(r+l)/2;
        mergesort(l, mid);
        mergesort(mid, r);
        tmp = l;
        for(i=l, j=mid; i<mid&&j<r; )
        {
            if(num[i]>num[j])
            {
                res[tmp++]=num[j++];
                sum+=(mid-i);
            }
            else
                res[tmp++]=num[i++];
        }
        for(; j<r; j++)
        {
            sum+=(mid-i);
            res[tmp++]=num[j];
        }
        for(; i<mid; i++)
            res[tmp++]=num[i];
        for(i=l; i<r; i++)
            num[i]=res[i];
    }
}

int main()
{
    int n, i, j;
    while(scanf("%d", &n) && n)
    {
        for(i=0, j=0; i<n*n; i++, j++)
        {
            scanf("%d", &num[j]);
            if(num[j]==0)
            {
                j--;
                sum=(n-1-i/n);///移动了多少行
            }
        }
        if(n==1)
        {
            printf("YES\n");
            continue;
        }
        mergesort(0, n*n-1);///减去一个0的位置
        printf((sum%2==0)?"YES\n":"NO\n");
    }
    return 0;
}
