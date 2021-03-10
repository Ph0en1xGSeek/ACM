#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {
    int n;
    char action[10];
    int st[300010];
    int num;
    int top;
    int cnt;
    int rmCnt;
    while (~scanf("%d", &n))
    {
        top = 0;
        cnt = 0;
        rmCnt = 0;
        for(int i = 0; i < (n<<1); i++)
        {
            getchar();
            scanf("%s", action);
            if(action[0] == 'a')
            {
                scanf("%d", &num);
                st[top++] = num;
            }
            else
            {
                rmCnt++;
                if(st[top-1] != 0 && rmCnt != st[top-1])
                {
                    cnt++;
//                    memset(st, 0, 4*top);
                    for(int i = top-1; i >= 0 && st[i] != 0; i--) st[i] = 0;
                    top--;
                }
                else
                {
                    top--;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}