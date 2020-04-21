#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    long long tmp;
    cin >> num;
    vector<long long> cost(num);
    for(int i = 0; i < num; ++i) {
        cin >> cost[i];
    }
    for(int i = 0; i < num; ++i) {
        cin >> tmp;
        cost[i] -= tmp;
    }
    int l = 0, r = 1;
    long long rest = cost[l];
    while(l != r) {
        if(rest >= 0) {
            rest += cost[r];
            r = (r + 1) % num;
        }else {
            l = (l - 1 + num) % num;
            rest += cost[l];
        }
    }
    vector<int> ans(num, 0);
    int cur = l;
    if(rest >= 0) {
        for(int i = 0; i < num; ++i) {
            if(rest >= 0) {
                ans[cur] = 1;
                cur = (cur - 1 + num) % num;
                rest = cost[cur];
            }else {
                ans[cur] = 0;
                cur = (cur - 1 + num) % num;
                rest += cost[cur];
            }
        }
    }
    for(int i = 0; i < num; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}