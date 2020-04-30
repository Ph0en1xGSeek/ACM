#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct StringCnt {
    string str;
    int cnt;
    StringCnt(const string &s, int _c) :str(s), cnt(_c) {};
    bool operator<(const StringCnt &sc) const {
        if(cnt == sc.cnt) {
            return str < sc.str;
        }
        return cnt > sc.cnt;
    }
};

int main() {
    int n, k;
    string str;
    cin >> n >> k;
    unordered_map<string, int> mp;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        ++mp[str];
    }
    priority_queue<StringCnt> q;
    for(auto p: mp) {
        q.push(StringCnt(p.first, p.second));
        if(q.size() > k) {
            q.pop();
        }
    }
    vector<StringCnt> arr;
    for(int i = 0; i < k; ++i) {
        arr.push_back(q.top());
        q.pop();
    }
    for(int i = k-1; i >= 0; --i) {
        cout << arr[i].str << " " << arr[i].cnt << endl;
    }
    return 0;
}
