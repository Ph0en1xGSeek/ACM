#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char arr[4] = {'v', '<', '^', '>'};

int main()
{

    char a;
    char b;
    int src, des;
    int num;
    int cnt;
    while(cin >> a >> b >> num)
    {
        cnt = 0;
        if(a == 'v') src = 0;
        else if(a == '<') src = 1;
        else if(a == '^') src = 2;
        else src = 3;

        if(b == 'v') des = 0;
        else if(b == '<') des = 1;
        else if(b == '^') des = 2;
        else des = 3;

        if((src + num) % 4 == des)
            cnt = 2;
        if(((src - num ) % 4 + 4)%4 == des)
            cnt++;
        if(cnt == 2)
            printf("cw\n");
        else if(cnt == 1)
            printf("ccw\n");
        else
            printf("undefined\n");
    }
    return 0;
}
