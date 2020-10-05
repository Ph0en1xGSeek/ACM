#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
char ch[11][11];

int main()
{
    int num;
    int flag;
    int record[10];
    scanf("%d", &num);
    while(num--)
    {
        for(int i = 0; i < 9; i++)
            scanf("%s", ch[i]);
        for(int i = 0 ; i < 9; i++)
        {
            flag = 1;
            memset(record, 0, sizeof(record));
            for(int j = 0 ; j < 9; j++)
            {
                if(record[ch[i][j]-'0'] && ch[i][j] != '0')
                {
                    flag = 0;
                    break;
                }
                else
                    record[ch[i][j]-'0'] = 1;
            }
            if(!flag)   goto tend;
        }
        for(int i = 0 ; i < 9; i++)
        {
            flag = 1;
            memset(record, 0, sizeof(record));
            for(int j = 0 ; j < 9; j++)
            {
                if(record[ch[j][i]-'0'] && ch[j][i] != '0')
                {
                    flag = 0;
                    break;
                }
                else
                    record[ch[j][i]-'0'] = 1;
            }
            if(!flag)
                goto tend;
        }
        printf("legal\n");
        continue;
        tend:
            printf("illegal\n");
    }
    return 0;
}
