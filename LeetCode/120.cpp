class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int num = triangle.size();
        if(num == 0){
            return 0;
        }
        vector<int> dp1(triangle.size(), 0);
        vector<int> dp2(triangle.size(), 0);
        vector<int> *cur = &dp1;
        vector<int> *pre = &dp2;
        (*pre)[0] = triangle[0][0];
        for(int i = 1; i < num; i++){
            for(int j = 0; j <= i; j++){
                int mi = 0x7fffffff;
                if(j > 0){
                    mi = min(mi, (*pre)[j-1] + triangle[i][j]);
                }
                if(j < i){
                    mi = min(mi, (*pre)[j] + triangle[i][j]);
                }
                (*cur)[j] = mi;
            }
            swap(cur, pre);
        }
        int ans = 0x7fffffff;
        for(int i = 0; i < num; i++){
            ans = min(ans, (*pre)[i]);
        }
        return ans;
    }
};