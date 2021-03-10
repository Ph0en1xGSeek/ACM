class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0) {
            return 0;
        }
        int cnt = 0;
        queue<pair<int, int>> q;
        vector<bool> flags(rows * cols, false);
        q.push({0, 0});
        flags[0] = true;
        ++cnt;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for(int i = 0; i < 4; ++i) {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];
                if(newx >= 0 && newy >= 0 && newx < rows && newy < cols && flags[newx * cols + newy] == false &&
                   cnt_sum(newx) + cnt_sum(newy) <= threshold) {
                    flags[newx * cols + newy] = true;
                    q.push({newx, newy});
                    ++cnt;
                }
            }
            
        }
        return cnt;
    }
    
    int cnt_sum(int num) {
        int cnt = 0;
        while(num > 0) {
            cnt += num % 10;
            num /= 10;
        }
        return cnt;
    }
private:
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
};