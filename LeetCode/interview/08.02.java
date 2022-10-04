class Solution {
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int row = obstacleGrid.length;
        if(row == 0) {
            return ans;
        }
        int col = obstacleGrid[0].length;
        if(col == 0) {
            return ans;
        }
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1) {
            return ans;
        }
        obstacleGrid[0][0] = 2;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(obstacleGrid[i][j] == 0) {
                    if(i > 0 && obstacleGrid[i-1][j] > 1) {
                        obstacleGrid[i][j] = 2;
                    }else if(j > 0 && obstacleGrid[i][j-1] > 1) {
                        obstacleGrid[i][j] = 3;
                    }
                }
            }
        }
        if(obstacleGrid[row-1][col-1] > 1) {
            int pos_x = row - 1;
            int pos_y = col - 1;
            while(pos_x >= 0 && pos_y >= 0) {
                ans.add(Arrays.asList(pos_x, pos_y));
                if(obstacleGrid[pos_x][pos_y] == 2) {
                    --pos_x;
                }else {
                    --pos_y;
                }
            }
            Collections.reverse(ans);
        }
        return ans;
    }
}