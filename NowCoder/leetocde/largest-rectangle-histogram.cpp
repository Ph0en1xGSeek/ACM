class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		int sz = heights.size();
		if(sz == 0) {
			return 0;
		}
		vector<int> left(sz, 0);
		vector<int> right(sz, 0);
		stack<int> left_mi, right_mi;
		for(int i = 0; i < sz; ++i) {
			while(!left_mi.empty() && heights[left_mi.top()] >= heights[i]) {
				left_mi.pop();
			}
			if(left_mi.empty()) {
				left[i] = -1;
			}else {
				left[i] = left_mi.top();
			}
			left_mi.push(i);
		}
		for(int i = sz - 1; i >= 0; --i) {
			while(!right_mi.empty() && heights[right_mi.top()] >= heights[i]) {
				right_mi.pop();
			}
			if(right_mi.empty()) {
				right[i] = sz;
			}else {
				right[i] = right_mi.top();
			}
			right_mi.push(i);
		}
		int ans = 0;
		for(int i = 0; i < sz; ++i) {
			ans = max(ans, heights[i] * (right[i] - left[i] - 1));
		}
		return ans;
	}
};