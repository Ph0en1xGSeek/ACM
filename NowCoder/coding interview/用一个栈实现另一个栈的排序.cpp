#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    stack<int> st1, st2;
    int cur, tmp;
    for(int i = 0; i < num; ++i) {
        cin >> cur;
        while(!st1.empty() && cur < st1.top()) {
            tmp = st1.top();
            st1.pop();
            st2.push(tmp);
        }
        while(!st2.empty() && cur > st2.top()) {
            tmp = st2.top();
            st2.pop();
            st1.push(tmp);
        }
        st1.push(cur);
    }
    while(!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
    }
    for(int i = 0; i < num; ++i) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;
    return 0;
}