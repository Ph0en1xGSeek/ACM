#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num;
    string str;
    bool flag = false;
    while(~scanf("%d", &num)) {
        cin >> str;
        int cnt8 = 0;
        int cnt_not_8 = 0;
        for(int i = 0; i < num - 11; i++) {
            if(str[i] == '8') {
                ++cnt8;
            }else {
                ++cnt_not_8;
            }
            if(cnt8 > (num - 11) / 2) {
                flag = true;
                break;
            }
            if(cnt_not_8 > (num - 11) / 2) {
                flag = false;
                break;
            }
        }
        if(cnt8 == cnt_not_8) {
            if(str[num-11] == '8') {
                flag = true;
            }else {
                flag = false;
            }
        }
        if(flag) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }

    return 0;
}
