class Solution {
public:
	bool canReach(vector<int> &arr, int start) {
		int size = arr.size();
		if(start >= size) {
			return false;
		}
		vector<bool> isvisited(size, false);
		queue<int> q;
		q.push(start);
        isvisited[start] = true;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			if(arr[cur] == 0) {
				return true;
			}
			if(cur - arr[cur] >= 0 && isvisited[cur - arr[cur]] == false) {
				isvisited[cur - arr[cur]] = true;
				q.push(cur - arr[cur]);
			}
			if(cur + arr[cur] < size && isvisited[cur + arr[cur]] == false) {
				isvisited[cur + arr[cur]] = true;
				q.push(cur + arr[cur]);
			}
		}
		return false;
	}
};