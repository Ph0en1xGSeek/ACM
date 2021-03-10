#include <iostream>
#include <stdio.h>
#include <string.h>
#define M 1000010

using namespace std;

int nex[M];
char ch[M];
int m;

void getnext()
{
    int i = 2;
    int j = 0;
    nex[1] = 0;
    while(i <= m )
    {
        if(j == 0 || ch[i] == ch[j+1])
        {

            j++;
            nex[i] = j;
            i++;
        }
        else
            j = nex[j];
    }
}


int main()
{
    while(scanf("%s", ch+1) && ch[1] != '.')
    {
        m = strlen(ch + 1);
        getnext();
        if(m%(m-nex[m]) == 0)
            printf("%d\n", m/(m-nex[m]));
        else
            printf("1\n");
    }
    return 0;
}
