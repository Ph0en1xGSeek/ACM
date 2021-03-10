#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int num;
    while(cin >> num) {
        vector<int> arr(num);
        vector<int> left(num);
        vector<int> right(num);
        for(int i = 0; i <num; ++i) {
            cin >> arr[i];
        }
        stack<int> st;
        for(int i = 0; i < num; ++i) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                left[i] = -1;
            }else {
                left[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int i = num-1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                right[i] = -1;
            }else {
                right[i] = st.top();
            }
            st.push(i);
        }
        for(int i = 0; i < num; ++i) {
            cout << left[i] << " " << right[i] << endl;
        }
    }
    return 0;
}