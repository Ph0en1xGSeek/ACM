class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left, right;
        int len = heights.size();
        left.resize(len);
        right.resize(len);
        for(int i = 0; i < len; i++){
            left[i] = i;
            int pos = i-1;
            while(pos >= 0){
                if(heights[pos] >= heights[i]){
                    pos = left[pos];
                }else{
                    break;
                }
                pos--;
            }
            left[i] = pos + 1;
        }
        for(int i = len-1; i >= 0; i--){
            right[i] = i;
            int pos = i + 1;
            while(pos < len){
                if(heights[pos] >= heights[i]){
                    pos = right[pos];
                }else{
                    break;
                }
                pos++;
            }
            right[i] = pos - 1;
        }
        int ans = 0;
        for(int i = 0; i < len; i++){
            int area = heights[i] * (right[i] - left[i] + 1);
            ans = max(ans, area);
        }
        return ans;
    }
};