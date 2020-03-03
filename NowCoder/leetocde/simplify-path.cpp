class Solution {
public:
	string simplifyPath(string path) {
		string res;
		int sz = path.size();
		stack<string> st;
		if(sz == 0) {
			return res;
		}
		int from = 0, to = 0;
		while(from < sz) {
			while(to < sz && path[to] != '/') {
				++to;
			}
			if(from == to) {
				from = to = to + 1;
			}else {
				string cur = path.substr(from, to - from);
				if(cur == "..") {
                    if(!st.empty())
					    st.pop();
				}else if(cur != ".") {
					st.push(cur);
				}
                from = to = to + 1;
			}
		}
		vector<string> output;
        if(st.empty()) {
           return "/";
        }
		while(!st.empty()) {
			output.push_back(st.top());
			st.pop();
		}
		reverse(output.begin(), output.end());
		for(string elem: output) {
			res = res +  "/";
            res = res + elem; 
		}
		return res;
	}
};
