class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital) {
		int sz = Capital.size();
		if(sz == 0 || k == 0) {
			return 0;
		}
		vector<pair<int, int>> p_c(sz);
		for(int i = 0; i < sz; ++i) {
			p_c[i].first = Capital[i];
			p_c[i].second = Profits[i];
		}
		sort(p_c.begin(), p_c.end(), [](pair<int, int> &a, pair<int, int> &b){
			if(a.first == b.first) {
				return a.second < b.second;
			}
			return a.first < b.first;
        });
        int pos = 0;
        priority_queue<int> prof_q;
        for(int i = 0; i < k; ++i) {
			while(pos < sz && p_c[pos].first <= W) {
				prof_q.push(p_c[pos++].second);
			}
			if(prof_q.empty()) {
				break;
			}
			int mx_prof = prof_q.top();
			prof_q.pop();
			W += mx_prof;
		}
		return W;
	}
};