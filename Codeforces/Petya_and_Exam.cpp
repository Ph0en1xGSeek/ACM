#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100005

using namespace std;

char arr[M];
char brr[M];
char good[30];
bool isGood[30];
bool hasStar;

int main()
{
    int num;
    while(~scanf("%s", good))
    {
        hasStar = false;
        memset(isGood, false, sizeof(isGood));
        scanf("%s", arr);
        int len = strlen(arr);
        for(int i = 0; i < strlen(good); i++)
        {
            isGood[good[i] - 'a'] = true;
        }
        for(int i = 0; i < len; i++)
            if(arr[i] == '*')
            {
                hasStar = true;
                break;
            }
        scanf("%d", &num);
        for(int i = 0 ; i < num; i++)
        {
            scanf("%s", brr);
            int lenb = strlen(brr);
            if(hasStar && len-1 > lenb)
            {
                printf("NO\n");
                continue;
            }
            else if(!hasStar && len != lenb)
            {
                printf("NO\n");
                continue;
            }
            else
            {
                int tmp = lenb - len;
                bool flag = true;
                for(int i = 0, j = 0; i < len; i++, j++)
                {
                    if(arr[i] >= 'a' && arr[i] <= 'z' && arr[i] != brr[j])
                    {
                        flag = false;
                        break;
                    }
                    else if(arr[i] == '?' && !isGood[brr[j]-'a'])
                    {
                        flag = false;
                        break;
                    }
                    else if(arr[i] == '*')
                    {
                        bool tmpFlag = true;
                        for(int k = 0; k < tmp+1; k++)
                        {
                            if(isGood[brr[j+k]-'a'])
                            {
                                tmpFlag = false;
                                break;
                            }
                        }
                        if(tmpFlag)
                            j += tmp;
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}
