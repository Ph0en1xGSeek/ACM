#include <stdio.h>
#define MAXN 1000
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>

int father[MAXN];
int str1[500], str2[500];//���ڵ��б�
int len1, len2;

void getFather(int node, int &len, int *str)
{
    //���ڲ�ȷ�����Ľ�������Ҫ�õ��������и��ڵ�Ƚ�
    while(node != 0)
    {
        node = father[node];
        str[len++] = node;
    }
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");
    memset(father, 0, sizeof(father));
    int n;
    fscanf(fp, "%d", &n);
    int num, to, tmp;
    for(int i = 1; i <= n; i++)
    {
        fscanf(fp, "%d", &num);
        while(num--)
        {
            fscanf(fp, "%d", &to);
            father[to] = i;//����
        }
    }

    fscanf(fp, "%d", &num);
    int a, b;
    while(num--)
    {
        fscanf(fp, "%d%d", &a, &b);
        fprintf(fp2, "%d %d ", a, b);
        if(a == b)
        {
            printf("%d\n", a);//ͬһ�����
            continue;
        }
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        len1 = len2 = 0;
        getFather(a, len1, str1);
        getFather(b, len2, str2);
        tmp = std::min(len1, len2);
        for(int i = tmp; i > 0; i--)//ͬ��ȵĸ����������ϱȽ�
        {
            if(str1[len1-i] == str2[len2-i])
            {
                fprintf(fp2, "%d\n", str1[len1-i]);
                break;
            }
        }
    }
    pclose(fp);
    pclose(fp2);
    return 0;
}
