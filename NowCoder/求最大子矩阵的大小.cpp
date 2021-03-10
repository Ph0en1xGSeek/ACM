#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> accu(m, 0);
    vector<int> left(m, 0);
    vector<int> right(m, 0);
    stack<int> st;
    int tmp;
    int ans = 0, sub_ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> tmp;
            if(tmp == 1) {
                ++accu[j];
            }else {
                accu[j] = 0;
            }
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int j = 0; j < m; ++j) {
            while(!st.empty() && accu[st.top()] >= accu[j]) {
                st.pop();
            }
            if(st.empty()) {
                left[j] = 0;
            }else {
                left[j] = st.top() + 1;
            }
            st.push(j);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int j = m - 1; j >= 0; --j) {
            while(!st.empty() && accu[st.top()] >= accu[j]) {
                st.pop();
            }
            if(st.empty()) {
                right[j] = m - 1;
            }else {
                right[j] = st.top() - 1;
            }
            st.push(j);
        }
        sub_ans = 0;
        for(int i = 0; i < m; ++i) {
            sub_ans = max(sub_ans, (right[i] - left[i] + 1) * accu[i]);
        }
        ans = max(ans, sub_ans);
    }
    cout << ans << endl;
    return 0;
}