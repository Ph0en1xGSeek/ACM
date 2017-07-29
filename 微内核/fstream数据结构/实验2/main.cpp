#include <stdio.h>
#include <string.h>
#define MAXN 1000
#include <fstream>

int father[MAXN<<1];
//���鼯
int getFather(int n)//��
{
    if(father[n] == 0)
        return n;
    return father[n] = getFather(father[n]);
}

void unions(int a, int b)//��
{
    a = getFather(a);
    b = getFather(b);
    if(a != b)
        father[a] = b;
}
int main()
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");
    int n, m;
    memset(father, 0, sizeof(father));
    fscanf(fp, "%d%d", &n, &m);
    int a, b;
    bool flag = true;
    while(m--)
    {
        fscanf(fp, "%d%d", &a, &b);
        unions(a, b + n);//a��b���Ϊ��ͬ����
        unions(b, a + n);
        if(getFather(a) == getFather(a+n) || getFather(b) == getFather(b+n))
        {
            flag = false;//����ì�����
        }
    }
    if(flag)
    {
        fprintf(fp2, "Yes\n");
        int temp = getFather(1);
        for(int i = 1; i <= n; i++)
            if(getFather(i) == temp)
                fprintf(fp2, "1");
            else
                fprintf(fp2, "0");
        printf("\n");
    }
    else
        fprintf(fp2, "No\n");
    pclose(fp);
    pclose(fp2);
    return 0;
}
