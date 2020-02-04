struct node {
    int x;
    int y;
    int index;
    
    node(): x(0), y(0), index(0){};
    node(int x_, int y_, int index_): x(x_), y(y_), index(index_){};
    bool operator<(const node &b) const {
        return x < b.x;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        vector<int> res;
        if(sz == 0) {
            return res;
        }else if(sz == 1) {
            res.push_back(-1);
            return res;
        }
        res.resize(sz, -1);
        vector<node> arr(sz);
        for(int i = 0;  i < sz; ++i) {
            arr[i].x = intervals[i][0];
            arr[i].y = intervals[i][1];
            arr[i].index = i;
        }
        sort(arr.begin(), arr.end());
        int left, right, target;
        for(int i = 0; i < sz; ++i) {
            target = intervals[i][1];
            left = 0;
            right = sz-1;
            while(left <= right) {
                int mid = left + ((right - left) >> 1);
                if(arr[mid].x >= target) {
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }
            if(left >= sz) {
                res[i] = -1;
            }else {
                res[i] = arr[left].index;
            }
        }
        return res;
    }
};