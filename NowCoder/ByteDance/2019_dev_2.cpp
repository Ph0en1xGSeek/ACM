#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
const int mod = 99997867;

int calculate(int x, vector<int> &memo) {
    if(x < 2) {
        return 0;
    }
    if(memo[x] != -1) {
        return memo[x];
    }
    long long ans = 1;
    ans = ((long long)x * (x-1) / 2) % mod;
    return memo[x] = (int)(ans);
}

int main() {
    int n, d;
    //vector<int> memo(n+1, -1);
    while(cin >> n >> d) {
        vector<int> building(n);
        vector<int> accu(1000001, 0);
        for(int i = 0; i < n; ++i) {
            cin >> building[i];
            ++accu[building[i]];
        }
        for(int i = 1; i <= 1000000; ++i) {
            accu[i] += accu[i-1];
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int num_of_building = accu[min(1000000, building[i] + d)] - accu[building[i]];
            //ans = (ans + calculate(num_of_building, memo)) % mod;
            ans = (ans + ((long long)num_of_building * (num_of_building - 1) / 2) % mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}