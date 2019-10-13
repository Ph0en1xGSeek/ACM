#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct tower {
    int index;
    int num;
}tower;

struct greater_cmp {
    bool operator()(const tower &tower1, const tower &tower2) const {
        return tower1.num > tower2.num;
    }
};

struct less_cmp {
    bool operator()(const tower &tower1, const tower &tower2) const {
        return tower1.num < tower2.num;
    }
};

int main() {
    int n, k;
    int s, m;
    scanf("%d%d", &n, &k);
    vector<tower> arr(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i].num);
        arr[i].index = i+1;
        sum += arr[i].num;
    }
    sum /= n;
    priority_queue<tower, vector<tower>, greater_cmp> min_q;
    priority_queue<tower, vector<tower>, less_cmp> max_q;
    for(int i = 0; i < n; ++i) {
        if(arr[i].num > sum) {
            max_q.push(arr[i]);
        }else {
            min_q.push(arr[i]);
        }
    }
    int i;
    vector<int> ans1;
    vector<int> ans2;
    for(i = 0; i < k; ++i) {
        tower mx = max_q.top();
        tower mi = min_q.top();
        if(mx.num - mi.num <= 1) {
            break;
        }
        ans1.push_back(mx.index);
        ans2.push_back(mi.index);
        max_q.pop();
        min_q.pop();
        mx.num -= 1;
        mi.num += 1;
        max_q.push(mx);
        min_q.push(mi);
    }
    tower mx = max_q.top();
    tower mi = min_q.top();
    s = mx.num - mi.num;
    m = i;
    printf("%d %d\n", s, m);
    for(int i = 0; i < m; ++i) {
        printf("%d %d\n", ans1[i], ans2[i]);
    }
    
    return 0;
}