#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long str2num(string &num) {
    long long ans = 0;
    int sign = 1;
    int size = num.size();
    int pos = 1;
    if(num[1] == '-') {
        sign = -1;
        ++pos;
    }
    while(pos < size-1) {
        ans = ans * 10 + num[pos] - '0';
        ++pos;
    }
    return sign * ans;
}

string num2str(long long num) {
    if(num == 0) {
        return "0";
    }
    string ans;
    if(num < 0) {
        ans += '-';
        num = -num;
    }
    while(num > 0) {
        ans += num % 10 + '0';
        num /= 10;
    }
    if(ans[0] == '-')
        reverse(ans.begin() + 1, ans.end());
    else 
        reverse(ans.begin(), ans.end());
    return ans;
}


int main() {
    string a, b;
    while(cin >> a >> b) {
        long long numa = str2num(a);
        long long numb = str2num(b);
        long long numc = numa + numb;
        string c = num2str(numc);
        cout << "\"" << c << "\"" << endl;
    }
    return 0;
}