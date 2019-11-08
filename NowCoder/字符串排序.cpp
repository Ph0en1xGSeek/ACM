#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int m;
    scanf("%d", &m);
    string str;
    vector<int> arr;
    int tmp;
    for(int i = 0; i < m; ++i) {
        tmp = 0;
        int mul = 1;
        cin >> str;
        int sz = str.size();
        for(int j = 0; j < 6; ++j) {
            tmp += (str[sz - 1 - j] - '0') * mul;
            mul *= 10;
        }
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < m; ++i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}