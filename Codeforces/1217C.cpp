#include <iostream>
#include <stdio.h>


using namespace std;


int main() {
    int t;
    string str;
    scanf("%d", &t);
    int cnt;
    int num;
    bool flag;
    while(t--) {
        cin >> str;
        cnt = 0;
        int sz = str.size();
        for(int i = 0; i < sz; ++i) {
            if(str[i] == '1') {
                ++cnt;
                num = 1;
                int l = i, r = i;
                while(1) {
                    flag = true;
                    ++r;
                    if(r >= sz) {
                        break;
                    }
                    num *= 2;
                    int find_zero = num - num / 2;
                    if(str[r] == '1') {
                        ++num;
                    }else {
                        --find_zero;
                    }
                    if(l >= find_zero) {
                        while(find_zero--) {
                            --l;
                            if(str[l] == '1') {
                                flag = false;
                                break;
                            }
                        }
                    }else {
                        break;
                    }
                    if(!flag) {
                        break;
                    }else {
                        ++cnt;
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
 
 