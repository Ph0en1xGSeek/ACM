#include <bits/stdc++.h>

using namespace std;
int main() {
    int num;
    while(cin >> num) {
        vector<int> arr(num);
        for(int i = 0; i < num; ++i) {
            cin >> arr[i];
        }
        if(num < 2) {
            cout << 0 << endl;
        }else if(num == 2) {
            cout << abs(arr[0] - arr[1]);
        }else {
            sort(arr.begin(), arr.end());
            deque<int> dq;
            int i = 0, j = arr.size() - 1; 
            int ans = 0;
            dq.push_back(arr[j--]);
            while(i < j) {
                if(i < j) {
                    dq.push_front(arr[i++]);
                }
                if(i < j) {
                    dq.push_back(arr[i++]);
                }
                if(i < j) {
                    dq.push_front(arr[j--]);
                }
                if(i < j) {
                    dq.push_back(arr[j--]);
                }
            }
            if(abs(arr[i] - dq.front()) > abs(arr[i] - dq.back())) {
                dq.push_front(arr[i]);
            }else{
                dq.push_back(arr[i]);
            }
            int pre = dq.front();
            dq.pop_front();
            while(!dq.empty()) {
                int cur = dq.front();
                dq.pop_front();
                ans += abs(pre - cur);
                pre = cur;
            }
            cout << ans << endl;
        }

    }
    return 0;
}