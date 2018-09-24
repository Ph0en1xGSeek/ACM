#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

struct node
{
    int num;//以该结点为结尾的字符串个数
    node* next[52];
}*dict, *re;

int add(char str[], node *head)
{
    //字典树的建立，并返回当前串加入后该串的个数
    node *p = head;
    for(int i = 0; str[i] != '\0'; i++)
    {
        int tmp = str[i]-'A';
        if(p->next[tmp] == NULL)
        {
            p->next[tmp] = new node;
            p->num = 0;
        }
        p = p->next[tmp];
    }
    p->num++;
    return p->num;
}

bool query(char str[], node *head)
{
    //字典树的查询
    node *p = head;
    for(int i = 0; str[i] != '\0'; i++)
    {
        int tmp = str[i]-'A';
        if(p->next[tmp] == NULL)
            return false;
        p = p->next[tmp];
    }
    if(p->num == 0)
        return false;
    else
        return true;
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");
    int n, tmp = 0, mx = 0;
    char str[15];
    fscanf(fp, "%d", &n);
    dict = new node;
    re = new node;
    while(n--)
    {
        fscanf(fp, "%s", str);
        add(str, dict);
    }
    fscanf(fp, "%d", &n);
    while(n--)
    {
        fscanf(fp, "%s", str);
        if(!query(str, dict))
            tmp = add(str, re);
        mx = max(mx, tmp);//不存在的串放入另外一个串，并求最大值
    }
    fprintf(fp2, "%d\n", mx);
    pclose(fp);
    pclose(fp2);
    return 0;
}
