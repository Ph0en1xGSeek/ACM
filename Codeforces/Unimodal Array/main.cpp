#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {


    int num;
    scanf("%d", &num);
    int state = 1;
    int cnt = 0;
    int tmp = 0;
    int pre = 0;

    do
    {
        cnt++;
        pre = tmp;
        scanf("%d", &tmp);
        if(tmp < pre) state = 3;
        if(tmp == pre) state = 2;
    }while(state == 1 && cnt < num);


    while(state == 2 && cnt < num)
    {
        cnt++;
        pre = tmp;
        scanf("%d", &tmp);
        if(tmp < pre) state = 3;
        if(tmp > pre) state = 4;
    }

    while(state == 3 && cnt < num)
    {
        cnt++;
        pre = tmp;
        scanf("%d", &tmp);
        if(tmp == pre) state = 4;
        if(tmp > pre) state = 4;
    }

    while(cnt < num)
    {
        scanf("%d", &tmp);
        cnt++;
    }

    if(state != 4)
        printf("YES\n");
    else
        printf("NO\n");


    return 0;
}