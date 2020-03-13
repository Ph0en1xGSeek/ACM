class Solution {
public:
	string predictPartyVictory(string senate) {
		queue<int> r;
		queue<int> d;
		int size = senate.size();
		for(int i = 0; i < size; ++i) {
			if(senate[i] == 'R') {
				r.push(i);
			}else {
				d.push(i);
			}
		}
		while(!r.empty() && !d.empty()) {
			if(r.front() < d.front()) {
				r.push(r.front() + size);
			}else {
				d.push(d.front() + size);
			}
			r.pop();
			d.pop();
		}
		if(r.empty()) {
			return "Dire";
		}else {
			return "Radiant";
		}
	}
};