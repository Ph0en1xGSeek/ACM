/**
��ͬ���ȵ����������ƴ�
Ҫô1�����࣬Ҫô0������
**/
#include <stdio.h>
#include <iostream>

char s[100008];
int main()
{
    int a=0, b=0, i;
    while(scanf("%s", s) != EOF)
    {
        for(i=0;s[i];i++)
        if(s[i]=='0')
            ++a;
        else
            ++b;
        printf("%d\n", a<b?a:b);
    }

}
