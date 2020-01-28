class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<int> q;
        int sz = num.size();
        vector<int> ret;
        if(sz == 0 || size == 0 || sz < size) {
            return ret;
        }
        for(int i = 0; i < size; ++i) {
            while(!q.empty() && num[i] > num[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ret.push_back(num[q.front()]);
        for(int i = size; i < sz; ++i) {
            if(q.front() <= i - int(size)) {
                q.pop_front();
            }
            while(!q.empty() && num[i] > num[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            ret.push_back(num[q.front()]);
        }
        return ret;
    }
};