class Solution {
public:
	int scheduleCourse(vector<vector<int>> &courses) {
		int size = courses.size();
		if(size == 0) {
			return 0;
		}
		sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){
			if(a[1] == b[1]) {
				return a[0] < b[0];
			}
			return a[1] < b[1];
        });
		int cur_time = 0;
		priority_queue<int> len_q;
		for(auto course: courses) {
			cur_time += course[0];
			len_q.push(course[0]);
			if(cur_time > course[1]) {
				cur_time -= len_q.top();
				len_q.pop();
			}
		}
		return (int)len_q.size();
	}
};