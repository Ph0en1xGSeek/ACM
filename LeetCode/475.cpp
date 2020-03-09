class Solution {
public:
	int findRadius(vector<int> &houses, vector<int> &heaters) {
		int houses_sz = houses.size();
		int heaters_sz = heaters.size();
        sort(heaters.begin(), heaters.end());
		if(heaters_sz == 0) {
			return INT_MAX;
		}
		if(houses_sz == 0) {
			return 0;
		}
		int left = 0, right = heaters_sz - 1;
		int ans = INT_MIN;
		int le_pos, ge_pos;
		for(int i = 0; i < houses_sz; ++i) {
			left = 0;
			right = heaters_sz - 1;
			while(left <= right) {
				int mid = left + ((right - left) >> 1);
				if(heaters[mid] > houses[i]) {
					right = mid - 1;
				}else {
					left = mid + 1;
				}
			}
			le_pos = right;
			ge_pos = left;
			int tmp = INT_MAX;
			if(le_pos >= 0) {
				tmp = min(tmp, houses[i] - heaters[le_pos]);
			}
			if(ge_pos < heaters_sz) {
				tmp = min(tmp, heaters[ge_pos] - houses[i]);
			}
			ans = max(ans, tmp);
		}
		return ans;
	}
};
