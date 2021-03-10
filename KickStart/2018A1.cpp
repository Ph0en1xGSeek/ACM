#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool judge(char* ch, int pos, int len) {
    for(int i = pos; i < len; ++i) {
        if(ch[i] > '4') {
            return true;
        }else if(ch[i] < '4') {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    char num[20];
    char new_num[20];
    long long ans;
    int flag;
    while(cin >> t) {
        for(int c = 1; c <= t; ++c) {
            
            getchar();
            scanf("%s", num);
            flag = -1;
            for(int i = 0; i < strlen(num); ++i) {
                new_num[i] = num[i];
                if((num[i] - '0') % 2 == 1) {
                    if(i == strlen(num) - 1) {
                        --new_num[i];
                        flag = 0;
                        break;
                    }else if(!judge(num, i+1, strlen(num)) || (num[i] - '0') == 9){
                        --new_num[i];
                        flag = 0;
                        ++i;
                        while(i < strlen(num)) {
                            new_num[i] = '8';
                            ++i;
                        }
                        break;
                    }else {
                        ++new_num[i];
                        flag = 1;
                        ++i;
                        while(i < strlen(num)) {
                            new_num[i] = '0';
                            ++i;
                        }
                        break;
                    }
                }
            }
            new_num[strlen(num)] = '\0';
            int tui = 0;
            ans = 0;
            long long pos = 1;
            if(flag < 0) {
                printf("Case #%d: %lld\n", c, 0);
            }else if(flag == 0){
                for(int i = strlen(num)-1; i >= 0; --i) {
                    int tmp = num[i] - new_num[i] - tui;
                    if(tmp < 0) {
                        tui = 1;
                        tmp += 10;
                    }else{
                        tui = 0;
                    }
                    ans += tmp * pos;
                    pos *= 10;
                }
                printf("Case #%d: %lld\n", c, ans);
            }else{
                for(int i = strlen(num)-1; i >= 0; --i) {
                    int tmp = new_num[i] - num[i] - tui;
                    if(tmp < 0) {
                        tui = 1;
                        tmp += 10;
                    }else{
                        tui = 0;
                    }
                    ans += tmp * pos;
                    pos *= 10;
                }
                printf("Case #%d: %lld\n", c, ans);
            }
        }
    }
    return 0;
}