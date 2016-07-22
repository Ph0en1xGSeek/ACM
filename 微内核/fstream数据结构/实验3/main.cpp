#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

struct node
{
    int num;//�Ըý��Ϊ��β���ַ�������
    node* next[52];
}*dict, *re;

int add(char str[], node *head)
{
    //�ֵ����Ľ����������ص�ǰ�������ô��ĸ���
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
    //�ֵ����Ĳ�ѯ
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
        mx = max(mx, tmp);//�����ڵĴ���������һ�������������ֵ
    }
    fprintf(fp2, "%d\n", mx);
    pclose(fp);
    pclose(fp2);
    return 0;
}
