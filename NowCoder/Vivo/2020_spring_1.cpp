class Solution {
public:
    /**
     * 实现方案
     * @param m int整型 最少m个键
     * @param n int整型 最多n个键
     * @return int整型
     */
    int solution(int m, int n) {
        // write code here
        if(n <= 0) {
            return 0;
        }
        arr[1][3] = arr[3][1] = 2;
        arr[7][9] = arr[9][7] = 8;
        arr[1][7] = arr[7][1] = 4;
        arr[3][9] = arr[9][3] = 6;
        arr[2][8] = arr[8][2] = arr[1][9] = arr[9][1] = arr[3][7] = arr[7][3] = arr[4][6] = arr[6][4] = 5;
        int ans = 0;
        int tmp = 0;
        visit[0] = true;
        helper(m, n, 1, 1, tmp);
        ans = 4 * tmp;
        tmp = 0;
        helper(m, n, 1, 2, tmp);
        ans += 4 * tmp;
        tmp = 0;
        helper(m, n, 1, 5, tmp);
        ans += tmp;
        return ans;
    }
    
    void helper(int m, int n, int cnt, int num, int &ans) {
        if(cnt >= m) {
            ++ans;
        }
        if(cnt + 1 > n) {
            return; 
        }
        visit[num] = true;
        for(int i = 1; i <= 9; ++i) {
            if(visit[i] == false && visit[arr[i][num]] == true) {
                helper(m, n, cnt+1, i, ans);
            }
        }
        visit[num] = false;
    }
private:
    int arr[10][10] = {0};
    bool visit[10] = {0};
};