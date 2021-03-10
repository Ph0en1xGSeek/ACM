#include <iostream>
#include <vector>

using namespace std;

bool check(int node1, int node2, vector<int> &lc1, vector<int> &rc1, vector<int> &lc2, vector<int> &rc2) {
	if(node2 == 0) {
		return true;
	}
	if(node1 != node2) {
		return false;
	}
	return check(lc1[node1], lc2[node2], lc1, rc1, lc2, rc2) && 
		check(rc1[node1], rc2[node2], lc1, rc1, lc2, rc2);
}

bool search(int node1, int node2, vector<int> &lc1, vector<int> &rc1, vector<int> &lc2, vector<int> &rc2) {
	if(node2 == 0) {
		return true;
	}
	if(node1 == 0) {
		return false;
	}
	return check(node1, node2, lc1, rc1, lc2, rc2) || 
        search(lc1[node1], node2, lc1, rc1, lc2, rc2) || 
        search(rc1[node1], node2, lc1, rc1, lc2, rc2);
}

int main() {
	int n1, root1, n2, root2;
	int tmp;
	cin >> n1 >> root1;
	vector<int> lc1(n1+1, 0), rc1(n1+1, 0);
	for(int i = 0; i < n1; ++i) {
		cin >> tmp;
		cin >> lc1[tmp] >> rc1[tmp];
	}
	cin >> n2 >> root2;
	vector<int> lc2(n2+1, 0), rc2(n2+1, 0);
	for(int i = 0; i < n2; ++i) {
		cin >> tmp;
		cin >> lc2[tmp] >> rc2[tmp];
	}
	if(n2 > n1) {
		return false;
	}
	if(search(root1, root2, lc1, rc1, lc2, rc2)) {
		cout << "true" << endl;
	}else {
		cout << "false" << endl;
	}
	
	return 0;
}
