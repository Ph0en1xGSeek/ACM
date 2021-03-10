#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;


int main() {
	int num, root, m;
	int lc, fa, rc;
	int node1, node2;
	while(cin >> num >> root) {
		vector<vector<int>> memo(num+1, vector<int>(num+1, -1));
		vector<int> father(num + 1, -1);
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
            if(memo[node1][node2] != -1) {
                cout << memo[node1][node2] << endl;
                continue;
            }
            vector<int> vec1, vec2;
            while(node1 != root) {
                vec1.push_back(node1);
                node1 = father[node1];
            }
            while(node2 != root) {
                vec2.push_back(node2);
                node2 = father[node2];
            }
            node1 = node2 = root;
            int pos1 = vec1.size() - 1;
            int pos2 = vec2.size() - 1;
            while(pos1 >= 0 && pos2 >= 0) {
                if(vec1[pos1] != vec2[pos2]) {
                    cout << node1 << endl;
                    break;
                }
                node1 = vec1[pos1];
                --pos1;
                --pos2;
            }
            if(pos1 < 0 || pos2 < 0) {
                cout << node1 << endl;
                if(pos1 < 0) {
                    for(int i = 0; i <= pos2; ++i) {
                        memo[vec2[i]][node1] = node1;
                        memo[node1][vec2[i]] = node1;
                    }
                }else if(pos2 < 0) {
                    for(int i = 0; i <= pos1; ++i) {
                        memo[vec1[i]][node1] = node1;
                        memo[node1][vec1[i]] = node1;
                    }
                }
            }
            for(int i = 0; i <= pos1; ++i) {
                for(int j = 0; j <= pos2; ++j) {
                    memo[vec1[i]][vec2[j]] = node1;
                    memo[vec2[j]][vec1[i]] = node1;
                }
            }
		}
	}
	return 0;
}
