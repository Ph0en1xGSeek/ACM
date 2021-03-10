#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int time;
    int level;
};

bool cmp(const node &a, const node &b) {
    if(a.time == b.time) {
        return a.level > b.level;
    }
    return a.time > b.time;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<node> machine(n);
    vector<node> task(m);
    for(int i = 0; i < n; ++i) {
        cin >> machine[i].time >> machine[i].level;
    }
    for(int i = 0; i < m; ++i) {
        cin >> task[i].time >> task[i].level;
    }
    sort(machine.begin(), machine.end(), cmp);
    sort(task.begin(), task.end(), cmp);
    vector<int> cnt(101, 0);
    int j = 0;
    long long ans = 0;
    int sum = 0;
    for(int i = 0; i < m; ++i) {
        while(j < n && machine[j].time >= task[i].time) {
            ++cnt[machine[j].level];
            ++j;
        }
        for(int tmp = task[i].level; tmp <= 100; ++tmp) {
            if(cnt[tmp] != 0) {                
                --cnt[tmp];
                ++sum;
                ans += 200 * (long long)task[i].time + 3 * (long long)task[i].level;
                break;
            }
        }
    }
    cout << sum << " " << ans << endl;
    return 0;
}