#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, int> &t1, const pair<int, int> &t2){
    if(t1.first == t2.first) {
        return t1.second < t2.second;
    }
    return t1.first < t2.first;
}

int main() {
    int num, dur;
    int h, m;
    scanf("%d", &num);
    vector<pair<int, int>> clocks(num);
    for(int i = 0; i < num; ++i) {
        scanf("%d%d", &clocks[i].first, &clocks[i].second);
    }
    sort(clocks.begin(), clocks.end(), cmp);
    scanf("%d", &dur);
    scanf("%d%d", &h ,&m);
    for(int i = 0; i < num; ++i) {
        int tmp_h = clocks[i].first;
        int tmp_m = clocks[i].second;
        tmp_m += dur;
        tmp_h += tmp_m / 60;
        tmp_m %= 60;
        if(tmp_h > h || (tmp_h == h && tmp_m > m)) {
            printf("%d %d\n", clocks[i-1].first, clocks[i-1].second);
            break;
        }
    }
    return 0;
}