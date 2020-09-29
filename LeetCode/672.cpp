class Solution {
public:

    int arr[4][4] = {0,1,1,1,0,2,3,4,0,2,4,7,0,2,4,8};
    int flipLights(int n, int m) {
        n = min(n, 3);
        m = min(m, 3);
        return arr[m][n];
    }
};