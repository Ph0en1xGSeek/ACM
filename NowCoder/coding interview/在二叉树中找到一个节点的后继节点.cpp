#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, root;
	int tmp;
	cin >> n >> root;
	vector<int> lc(n+1, 0), rc(n+1, 0), fa(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        cin >> lc[tmp] >> rc[tmp];
        fa[lc[tmp]] = tmp;
        fa[rc[tmp]] = tmp;
    }
    fa[0] = 0;
	int q;
	cin >> q;
	if(rc[q] == 0) {
		tmp = q;
		while(tmp != 0 && rc[fa[tmp]] == tmp) {
			tmp = fa[tmp];
		}
        tmp = fa[tmp];
	}else {
		tmp = rc[q];
        while(lc[tmp] != 0) {
            tmp = lc[tmp];
        }
	}
	cout << tmp << endl;
	return 0;
}
