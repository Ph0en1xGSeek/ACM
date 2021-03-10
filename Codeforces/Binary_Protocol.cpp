#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    int num;
    char str[100];
    int cnt = 0;
    char result[100];
    int pos = 0;
    scanf("%d", &num);
    getchar();
    scanf("%s", str);
    for(int i = 0; i < num; i++)
    {
        if(str[i] == '1')
        {
            cnt++;
        }
        else
        {
            result[pos++] = cnt + '0';
            cnt = 0;
        }
    }
    result[pos++] = cnt + '0';
    result[pos++] = '\0';
    printf("%s\n", result);
    return 0;
}