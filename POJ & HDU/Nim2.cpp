/**����Ϊ��Ϊ�ذ�̬����Ӯ������ذ�̬��Ҳ���������Ͳ�Ϊ0
��ѡĳ�����������������ʹ�����һЩʯ�ӱ�������������;��У�
�ж��ٸ��������� ���ж�����Ӯ��������Ĳ��趼�ɶ��ֵ��߷�������**/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int num;
    int ans, tot;
    int arr[1005];
    while(scanf("%d", &num) && num)
    {
        tot = 0;
        ans = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
            tot ^= arr[i];
        }
        if(tot == 0)
            printf("0\n");
        else
        {
            for(int i = 0; i < num; i++)
            {
                if((tot ^ arr[i]) < arr[i])
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
