#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> &in_order, int from, int to) {
    if(from == to) {
        int ret = in_order[from];
        in_order[from] = 0;
        return ret;
    }
    int mid = (from + to) >> 1;
    int left_sum = dfs(in_order, from, mid-1);
    int right_sum = dfs(in_order, mid+1, to);
    int ret = left_sum + right_sum + in_order[mid];
    in_order[mid] = left_sum + right_sum;
    return ret;
}

int main() {
    string line;
    getline(cin, line);
    vector<int> in_order;
    getline(cin, line);
    istringstream is(line);
    int tmp;
    while(is >> tmp) {
        in_order.push_back(tmp);
    }
    int sz = in_order.size();
    if(sz == 0) {
        printf("\n");
        return 0;
    }
    dfs(in_order, 0, sz-1);
    for(int i = 0; i < sz; ++i) {
        printf("%d ", in_order[i]);
    }
    printf("\n");
    return 0;
}