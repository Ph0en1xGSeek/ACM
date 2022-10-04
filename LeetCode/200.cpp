class Solution {
public:
    
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<char>> &grid, int x, int y, int n, int m){
        if(grid[x][y] == '1'){
            grid[x][y] = '0';
        }else{
            return;
        }
        for(int i = 0; i < 4; i++){
            int n_x = x + dir[i][0];
            int n_y = y + dir[i][1];
            if(n_x >= 0 && n_y >= 0 && n_x < n && n_y < m){
                dfs(grid, n_x, n_y, n, m);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        if(m == 0){
            return 0;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};