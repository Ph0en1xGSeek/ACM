#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string str;
    while(cin >> str) {
        int size = str.size();
        int pos = 0;
        stack<string> cur_st;
        stack<int> repeat_st;
        string cur;
        int repeat = 1;
        while(pos < size) {
            if(str[pos] == '[') {
                cur_st.push(cur);
                cur = "";
                repeat_st.push(repeat);
                repeat = 0;
                ++pos;
                while(pos < size && str[pos] >= '0' && str[pos] <= '9') {
                    repeat = repeat * 10;
                    repeat += str[pos] - '0';
                    ++pos;
                }
                ++pos;
            }else if(str[pos] == ']') {
                string pre_cur = cur_st.top();
                cur_st.pop();
                int pre_repeat = repeat_st.top();
                repeat_st.pop();
                for(int i = 0; i < repeat; ++i) {
                    pre_cur += cur;
                }
                repeat = pre_repeat;
                cur = pre_cur;
                ++pos;
            }else if(str[pos] >= 'A' && str[pos] <= 'Z') {
                cur += str[pos];
                ++pos;
            }
        }
        cout << cur << endl;
    }
    return 0;
}