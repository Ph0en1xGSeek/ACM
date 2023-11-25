class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        int rows = plants.size();
        if (rows == 0) {
            return false;
        }
        int cols = plants[0].size();
        if (cols == 0) {
            return false;
        }
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0) {
            if (plants[i][j] == target) {
                return true;
            } else if (plants[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};