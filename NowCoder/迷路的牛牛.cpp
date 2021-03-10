#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    string str;
    int cur = 0;
    cin >> str;
    for(int i = 0; i < num; ++i) {
        if(str[i] == 'L') {
            --cur;
        }else {
            ++cur;
        }
    }
    cur = ((cur % 4) + 4) % 4;
    if(cur == 0) {
        printf("N\n");
    }else if(cur == 1) {
        printf("E\n");
    }else if(cur == 2) {
        printf("S\n");
    }else {
        printf("W\n");
    }
    return 0;
}