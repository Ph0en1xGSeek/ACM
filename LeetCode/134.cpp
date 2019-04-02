class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, left = 0, accumulate = 0;
        for(int i = 0; i < gas.size(); i++){
            left += gas[i] - cost[i];
            if(left < 0){
                ans = i+1;
                accumulate += left;
                left = 0;
            }
        }
        if(left + accumulate >= 0){
            return ans;
        }else{
            return -1;
        }
    }
};