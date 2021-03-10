#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    int pos = 0;
    int size = input.size();
    int cnt[2] = {0};
    int level[2][18] = {{0}};
    int state = 0;
    int mid_pos = 0;
    int num;
    string str;
    while(pos < size) {
        if(input[pos] >= '0' && input[pos] <= '9') {
            num = 0;
            while(input[pos] >= '0' && input[pos] <= '9') {
                num *= 10;
                num += input[pos] - '0';
                ++pos;
            }
            if(num == 2) {
                num = 15;
            }
            ++level[state][num];
            ++cnt[state];
        }else {
            num = pos;
            while((input[pos] >= 'A' && input[pos] <= 'Z') || (input[pos] >= 'a' && input[pos] <= 'z')) {
                ++pos;
            }
            str = input.substr(num, pos - num);
            if(str == "J") {
                level[state][11]++;
            }else if(str == "Q") {
                level[state][12]++;
            }else if(str == "K") {
                level[state][13]++;
            }else if(str == "A") {
                level[state][14]++;
            }else if(str == "joker") {
                level[state][16]++;
            }else if(str == "JOKER") {
                level[state][17]++;
            }
            ++cnt[state];
        }

        if(input[pos] == '-') {
            mid_pos = pos;
            state = 1;
        }
        ++pos;
    }


    if(cnt[0] == cnt[1]) {
        for(int i = 3; i < 17; ++i) {
            if(level[0][i] == 0 && level[1][i] != 0) {
                cout << input.substr(0, mid_pos) << endl;
                break;
            }else if(level[1][i] == 0 && level[0][i] != 0) {
                cout << input.substr(mid_pos + 1, size - mid_pos - 1) << endl;
                break;
            }
        }
    }else {
        if((cnt[0] == 2 && level[0][16] > 0) || (cnt[1] == 2 && level[1][16] > 0)) {
            cout << "joker JOKER" << endl;
        }else if(cnt[0] == 4) {
            cout << input.substr(0, mid_pos) << endl;
        }else if(cnt[1] == 4) {
            cout << input.substr(mid_pos + 1, size - mid_pos - 1) << endl;
        }else {
            cout << "ERROR" << endl;
        }
    }
    return 0;
}