#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, root;
	cin >> n >> root;
	vector<int> lc(n+1, 0), rc(n+1, 0);
    int node;
    for(int i = 0; i < n; ++i) {
        cin >> node;
        cin >> lc[node] >> rc[node];
    }
	int cnt = 0;
	int cur = root;
	int pre = -1;
	int ans1, ans2;
	while(cur != 0) {
		if(lc[cur] != 0) {
			int tmp = lc[cur];
			while(rc[tmp] != 0 && rc[tmp] != cur) {
				tmp = rc[tmp];
			}
			if(rc[tmp] == cur) {
				rc[tmp] = 0;
                if(pre > cur) {
                    if(cnt == 0) {
                        ans1 = pre;
                        ans2 = cur;
                    }else {
                        ans2 = cur;
                    }
                    ++cnt;
                }
                pre = cur;
				cur = rc[cur];
			}else {
				rc[tmp] = cur;

				cur = lc[cur];
			}
		}else {
			if(pre > cur) {
				if(cnt == 0) {
					ans1 = pre;
					ans2 = cur;
				}else {
					ans2 = cur;
				}
				++cnt;
			}
			pre = cur;
            cur = rc[cur];
		}
	}
	cout << ans2 << " " << ans1 << endl;
	return 0;
}
