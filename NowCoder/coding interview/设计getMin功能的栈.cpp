#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
	const int INT_MAX = 0x7fffffff;
	int num;
	string str;
	int input;
	while(cin >> num) {
		stack<int> st;
		stack<int> mi;
		for(int i = 0; i < num; ++i) {
			cin >> str;
			if(str == "push") {
				cin >> input;
				if(mi.empty()) {
					st.push(input);
					mi.push(input);
				}else {
					if(input < mi.top()) {
						st.push(input);
						mi.push(input);
					}else {
						st.push(input);
						mi.push(mi.top());
					}
				}
			}else if(str == "getMin") {
				if(!mi.empty()) {
					cout << mi.top() << endl;
				}
			}else if(str == "pop") {
				if(!mi.empty()) {
					st.pop();
					mi.pop();
				}
			}
		}
	}
	return 0;
}