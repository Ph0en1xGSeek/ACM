#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;

int getlevel(int node, vector<int> &father, vector<int> &level) {
    if(level[node] != -1) {
        return level[node];
    }
    return level[node] = getlevel(father[node], father, level) + 1;
}


int main() {
	int num, root, m;
	int lc, fa, rc;
	int node1, node2;
	while(cin >> num >> root) {
		vector<int> father(num + 1, -1);
        vector<int> level(num + 1, -1);
        level[root] = 0;
		for(int i = 1; i <= num; ++i) {
			cin >> fa >> lc >> rc;
			father[lc] = father[rc] = fa;
		}
		cin >> m;
		while(m--) {
			cin >> node1 >> node2;
            if(node1 == node2) {
                cout << node1 << endl;
                continue;
            }
            int level1 = getlevel(node1, father, level);
            int level2 = getlevel(node2, father, level);
            while(node1 != node2) {
                if(level1 > level2) {
                    node1 = father[node1];
                    --level1;
                }else if(level1 < level2) {
                    node2 = father[node2];
                    --level2;
                }else {
                    node1 = father[node1];
                    node2 = father[node2];
                    --level1;
                    --level2;
                }
            }
            cout << node1 << endl;
		}
	}
	return 0;
}


