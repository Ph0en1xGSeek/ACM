#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    int ca;
    int num;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        scanf("%d %s", &num, str);
        if(next_permutation(str, str+strlen(str)))
            printf("%d %s\n", i, str);
        else
            printf("%d %s\n", i, "BIGGEST");
    }

    return 0;
}
/**ȫ���е��㷨����β��ʼ���½����о����Ѿ�ȫ���кõ�������
������һ�����лὫ�½������ֽ����������������Ǹ�����������佻��λ��
�ұ߻ָ���˳��*/
