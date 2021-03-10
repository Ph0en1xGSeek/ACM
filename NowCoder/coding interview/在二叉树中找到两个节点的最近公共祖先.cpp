#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;


int main() {
	int num, root;
	int lc, fa, rc;
	int node1, node2;
	while(cin >> num >> root) {
		vector<int> father(num + 1, -1);
		for(int i = 1; i <= num; ++i) {
			cin >> fa >> lc >> rc;
			father[lc] = father[rc] = fa;
		}
		cin >> node1 >> node2;
		if(node1 == node2) {
			cout << node1 << endl;
			continue;
		}
		stack<int> st1, st2;
		while(node1 != root) {
			st1.push(node1);
            node1 = father[node1];
		}
		while(node2 != root) {
			st2.push(node2);
            node2 = father[node2];
		}
		node1 = node2 = root;
		while(!st1.empty() && !st2.empty()) {
			if(st1.top() != st2.top()) {
				cout << node1 << endl;
				break;
			}
			node1 = st1.top();
			st1.pop();
			st2.pop();
		}
		if(st1.empty() || st2.empty()) {
			cout << node1 << endl;
		}
	}
	return 0;
}
