#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> left(n), right(n), arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    stack<int> st, st2;
    for(int i = 0; i < n; ++i) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if(st.empty()) {
            left[i] = -1;
        }else {
            left[i] = st.top();
        }
        st.push(i);
    }
    for(int i = n-1; i >= 0; --i) {
        while(!st2.empty() && arr[st2.top()] >= arr[i]) {
            st2.pop();
        }
        if(st2.empty()) {
            right[i] = -1;
        }else {
            right[i] = st2.top();
        }
        st2.push(i);
    }
    for(int i = 0; i < n; ++i) {
        cout << left[i] << " " << right[i] << endl;
    }
    return 0;
}