#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first > p2.first;
    }
};

struct cmp2 {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second < p2.second;
    }
};

int main() {
    long long n, w, k;
    pair<int, int> tmp;
    while(cin >> n >> w >> k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> costs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> profits;
        vector<int> cost(n);
        vector<int> profit(n);
        for(int i = 0; i < n; ++i) {
            cin >> cost[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> profit[i];
            costs.push({cost[i], profit[i]});
        }
        while(k--) {
            while(!costs.empty() && costs.top().first <= w) {
                tmp = costs.top();
                costs.pop();
                profits.push(tmp);
            }
            if(profits.empty()) {
                break;
            }
            tmp = profits.top();
            profits.pop();
            w += tmp.second;
        }
        cout << w << endl;
    }
    return 0;
}