#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[7] = {16,7,8,1,1,2,3};

int main()
{
    int ca;
    bool ma, pao;
    scanf("%d", &ca);
    int ans1, ans2;
    while(ca--)
    {
        char ch[5];
        ans1 = ans2 = 0;
        int num;
        scanf("%d", &num);
        ma = pao = false;
        for(int i = 0; i < num; i++)
        {

            scanf("%s", ch);
            ans1 += arr[ch[0]-'A'];
            if(ch[0] == 'B')
                ma = true;
            else if(ch[0] == 'C')
                pao = true;
        }
        if(ma == false || pao == false)
            ans1 = max(1, ans1-1);
        scanf("%d", &num);
        ma = pao = false;
        for(int i = 0; i < num; i++)
        {

            scanf("%s", ch);
            ans2 += arr[ch[0]-'A'];
            if(ch[0] == 'B')
                ma = true;
            else if(ch[0] == 'C')
                pao = true;
        }
        if(ma == false || pao == false)
            ans2 = max(1, ans2-1);
        if(ans1 == ans2)
            printf("tie\n");
        else if(ans1 < ans2)
            printf("black\n");
        else
            printf("red\n");
    }
    return 0;
}
