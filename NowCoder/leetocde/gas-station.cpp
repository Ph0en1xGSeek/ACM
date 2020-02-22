class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sz = gas.size();
        if(sz == 0) {
            return 0;
        }
        int accumulate = 0, sum = 0, left = 0;
        for(int i = 0; i < sz; ++i) {
            sum += gas[i] - cost[i];
            if(sum < 0) {
                accumulate -= sum;
                sum = 0;
                left = i + 1;
            }
        }
        if(sum - accumulate >= 0) {
            return left;
        }else {
            return -1;
        }
    }
};