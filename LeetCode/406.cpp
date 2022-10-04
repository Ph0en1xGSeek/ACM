class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int sz = people.size();
        vector<bool> isFilled(sz);
        vector<vector<int>> ret(sz);
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]) {
               return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int pos = 0;
        while(pos < sz) {
            int i = pos;
            int cnt = 0;
            int j = 0;
            while(i < sz && people[i][0] == people[pos][0]) {
                for(; j < sz; ++j) {
                    if(isFilled[j] == false) {
                        ++cnt;
                        if(cnt == people[i][1] + 1) {
                            isFilled[j] = true;
                            ret[j] = people[i];
                            ++j;
                            break;
                        }
                    }
                }
                ++i;
            }
            pos = i;
        }
        return ret;
    }
};