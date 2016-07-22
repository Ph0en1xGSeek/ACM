#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

int father[30];///1~26

int main()
{
    for(int i = 0; i < 30; i++)
        father[i] = i;
    bool added[100];
    string from[100], to[100];
    bool flag = true;
    string who;
    int num;
    printf("条件个数：\n");
    scanf("%d", &num);
    printf("输入条件\n");
    for(int i = 0; i < num; i++)
    {
        cin >> from[i];
        cin >> to[i];
    }
    printf("谁的闭包\n");
    cin >> who;

    for(int i = 0; i < who.length(); i++)
    {
        int w = who[i] - 'A' +1;
        father[w] = -1;
    }
    memset(added, false, sizeof(added));
    while(flag)
    {
        flag = false;
        for(int i = 0; i < num; i++)
        {
            if(added[i])    continue;
            for(int j = 0; j < from[i].length(); j++)
            {
                int tmp = from[i][j] - 'A' + 1;
                if(father[tmp] != -1)
                       goto next;
            }
            flag = true;
            added[i] = true;
            for(int j = 0; j < to[i].length(); j++)
            {
                int tmp = to[i][j] - 'A' + 1;
                father[tmp] = -1;
            }
            next:;
        }
    }
    printf("属性闭包\n");
    for(int i = 1; i < 27; i++)
        if(father[i] == -1)
            printf("%c", i - 1 + 'A');
    printf("\n");
    system("PAUSE");
    return 0;
}
