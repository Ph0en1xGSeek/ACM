#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 1000007

using namespace std;

char str[M*2];
char tmp[M];
int father[M*2];

int getFather(int x)
{
    if(father[x] == 0)
        return x;
    else
        return father[x] = getFather(father[x]);
}

int main() {

    memset(str, 0, sizeof(str));
    memset(father, 0, sizeof(father));
    int num;
    int k;
    int pos;
    int mxPos = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%s", tmp);
        scanf("%d", &k);
        int len = strlen(tmp);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &pos);
            pos--;
            int curPos = getFather(pos);
            while (curPos-pos < len)
            {
                str[curPos] = tmp[curPos-pos];
                father[curPos] = curPos + 1;
                curPos = getFather(curPos);
            }
            mxPos = max(mxPos, pos + len -1);
        }
    }

    for(int i = 0; i < mxPos; i++)
        if(!str[i])
            str[i] = 'a';


    printf("%s\n", str);

    return 0;
}