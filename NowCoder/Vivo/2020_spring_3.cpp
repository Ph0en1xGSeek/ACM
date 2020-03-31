class Solution {
public:
    /**
     * 
     * @param n int整型 第n天
     * @return int整型
     */
    int solution(int n) {
        // write code here
        int ans = 0;
        int pos = 1;
        while(1) {
            int tmp = pos * (pos + 1) / 2;
            if(tmp < n) {
                ans += pos * pos;
            }else {
                ans += pos * (n - (pos-1) * pos / 2);
                break;
            }
            ++pos;
        }
        return ans;
    }
};