#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct work {
    int cost;
    int gain;
    bool operator<(work &b) const {
        if(cost == b.cost) {
            return gain < b.gain;
        }
        return cost < b.cost;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<work> works(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &works[i].cost, &works[i].gain);
    }
    sort(works.begin(), works.end());
    int pos = 0;
    int mx = -0x7fffffff;
    for(int i = 0; i < m; ++i) {
        if(works[i].gain > mx) {
            mx = works[i].gain;
            works[pos].cost = works[i].cost;
            works[pos].gain = works[i].gain;
            ++pos;
        }
    }
    for(int i = 0; i < m; ++i) {
        int ability;
        scanf("%d", &ability);
        int l = 0, r = pos;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(works[mid].cost <= ability) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        if(l == 0) {
            printf("0\n");
        }else {
            printf("%d\n", works[l-1].gain);
        }
    }
    return 0;
}