#include <stdio.h>
int main()
{
    int y,n,k,i;
    scanf("%d %d %d",&y,&k,&n);
    for(i=(y/k+1)*k;i<=n;i+=k)//�Ӵ���y�ĵ�һ���ɳ�����n
    {
        printf("%d ",i-y);
    }
    if((y/k+1)*k>n)
    {
        printf("-1");
    }
    return 0;
}
