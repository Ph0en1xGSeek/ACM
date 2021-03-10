#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iomanip>

using namespace std;

bool cmp(char a, char b)
{
    return a > b;
}

int main()
{
    char str1[20];
    char str2[20];
    char tmp;
    int arr[15];

    while(~scanf("%s", str1))
    {
        memset(arr, 0, sizeof(arr));
        getchar();
        scanf("%s", str2);
        getchar();
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        if(len2 > len1)
        {
            sort(str1, str1+len1, cmp);
        }
        else
        {
            bool flag = false;
            for(int i = 0; i < len1; i++)
            {
                arr[str1[i] - '0']++;
                str1[i] = str2[i];
            }
            for(int i = 0; i < len2; i++)
            {
                int j;
                if(flag == false)
                    j = str1[i] - '0';
                else
                    j = 9;
                for(; j >= 0; j--)
                {
                    if(arr[j] > 0)
                    {
                        arr[j]--;
                        str1[i] = j+'0';
                        if(j < str2[i] - '0')
                            flag = true;
                        break;
                    }
                }
                if(j == -1 && flag == false)
                {
                    i--;
                    arr[str1[i]-'0']++;
                    str1[i]--;
                    i--;
                }
            }
        }
        printf("%s\n", str1);
    }
    return 0;
}
