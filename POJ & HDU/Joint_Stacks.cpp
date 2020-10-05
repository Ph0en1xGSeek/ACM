#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[100010];

int headA[100010], headB[100010];
int headTmp[100010];
int top1, top2, top3;

int main()
{
    int num;
    char str[10];
    char s[5];
    int ca = 1;
    while(~scanf("%d", &num) && num != 0)
    {
        top1 = top2 = top3 = -1;
        memset(arr, 0, sizeof(arr));
        printf("Case #%d:\n", ca++);
        for(int i = 0; i < num; i++)
        {
            scanf("%s", str);
            scanf("%s", s);
            if(str[1] == 'u')
            {
                scanf("%d", &arr[i]);
                if(s[0] == 'A')
                    headA[++top1] = i;
                else if(s[0] == 'B')
                    headB[++top2] = i;
            }
            else if(str[1] == 'o')
            {
                if(s[0] == 'A')
                {
                    if(top1 == -1)
                        printf("%d\n", arr[headTmp[top3--]]);
                    else
                        printf("%d\n", arr[headA[top1--]]);
                }
                else if(s[0] == 'B')
                {
                    if(top2 == -1)
                        printf("%d\n", arr[headTmp[top3--]]);
                    else
                        printf("%d\n", arr[headB[top2--]]);
                }
            }
            else if(str[1] == 'e')
            {
                scanf("%s", s);
                int i = 0, j = 0;
                while(i <= top1 && j <= top2)
                {
                    if(headA[i] < headB[j])
                        headTmp[++top3] = headA[i++];
                    else
                        headTmp[++top3] = headB[j++];
                }
                while(i <= top1)
                    headTmp[++top3] = headA[i++];
                while(j <= top2)
                    headTmp[++top3] = headB[j++];

//                top3 = merge(headA, headA + top1+1,
//			               headB, headB + top2+1,
//			               headTmp + top3+1) - headTmp-1;
                top1 = top2 = -1;
            }
        }
    }
    return 0;
}
