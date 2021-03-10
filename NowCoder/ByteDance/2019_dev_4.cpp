#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace std {
	template<>
	struct hash<pair<int, int>> {
		size_t operator()(const pair<int, int> &p) const {
			return hash<int>()(p.first) ^ hash<int>()(p.second);
		}
	};
}


int main() {
    int ca, frames, nodes;
	pair<int, int> p;
	int ans = -1;
    cin >> ca;
    while(ca--) {
		ans = 0;
        unordered_map<pair<int, int>, int> mp;
        cin >> frames;
		for(int i = 0; i < frames; ++i) {
			cin >> nodes;
			for(int j = 0; j < nodes; ++j) {
				cin >> p.first >> p.second;
				if(mp.find(p) == mp.end()) {
					mp[p] = 1;
					ans = max(ans, 1);
				}else if(mp[p] < i - 1){
					mp[p] = 1;
				}else {
					++mp[p];
					ans = max(ans, mp[p]);
				}
			}
		}
		cout << ans << endl;
    }
    return 0;
}