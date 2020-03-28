#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int num;
    stack<int> st;
    while(cin >> num) {
        if(num == 0) {
            cout << 0 << endl;
        }
        vector<int> arr(num);
        vector<int> left(num), right(num);
        for(int i = 0; i < num; ++i) {
            cin >> arr[i];
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < num; ++i) {
            left[i] = st.size();
            while(!st.empty() && st.top() <= arr[i]) st.pop();
            st.push(arr[i]);
        }
        while(!st.empty()) st.pop();
        for(int i = num - 1; i >= 0; --i) {
            right[i] = st.size();
            while(!st.empty() && st.top() <= arr[i]) st.pop();
            st.push(arr[i]);
        }
        for(int i = 0; i < num; ++i) {
            cout << left[i] + right[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}