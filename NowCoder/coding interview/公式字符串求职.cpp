#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;


int calculate(string &s) {
    int size = s.size();
    if(size == 0) {
        return 0;
    }
    int sign = 0;
    int pre = 0;
    int num = 0;
    int res = 0;
    stack<int> st;
    for(int i = 0; i < size; ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            num = 0;
            while(i < size && s[i] >= '0' && s[i] <= '9') {
                num *= 10;
                num += s[i] - '0';
                ++i;
            }
            --i;
            if(sign == 0) {
                pre = num;
                res += num;
            }else if(sign == 1) {
                pre = -num;
                res -= num;
            }else if(sign == 2) {
                res -= pre;
                res += pre * num;
                pre *= num;
            }else {
                res -= pre;
                res += pre / num;
                pre /= num;
            }
        }else if(s[i] == '(') {
            st.push(res);
            st.push(sign);
            st.push(pre);
            res = 0;
            sign = 0;
            pre = 0;
        }else if(s[i] == ')') {
            int pre_pre = st.top();
            st.pop();
            int pre_sign = st.top();
            st.pop();
            int pre_res = st.top();
            st.pop();
            if(pre_sign == 0) {
                pre_pre = res;
                pre_res += res;
            }else if(pre_sign == 1) {
                pre_pre = -res;
                pre_res -= res;
            }else if(pre_sign == 2) {
                pre_res -= pre_pre;
                pre_res += pre_pre * res;
                pre_pre *= res;
            }else {
                pre_res -= pre_pre;
                pre_res += pre_pre / res;
                pre_pre /= res;
            }
            pre = pre_pre;
            res = pre_res;
        }else if(s[i] == '+') {
            sign = 0;
        }else if(s[i] == '-') {
            sign = 1;
        }else if(s[i] == '*') {
            sign = 2;
        }else if(s[i] == '/') {
            sign = 3;
        }
    }
    return res;
}

int main() {
    string str;
    while(cin >> str) {
        cout << calculate(str) << endl;
    }
    return 0;
}