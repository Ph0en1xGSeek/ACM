class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if(row == 0) {
            return false;
        }
        int col = array[0].size();
        if(col == 0) {
            return false;
        }
        int i = 0, j = col-1;
        while(i < row && j >= 0) {
            if(array[i][j] == target) {
                return true;
            }else if(array[i][j] > target) {
                --j;
            }else {
                ++i;
            }
        }
        return false;
    }
};