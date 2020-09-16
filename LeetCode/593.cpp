class Solution {
public:
    bool isEqual(const vector<int> &p1, const vector<int> &p2, const vector<int> &p3, const vector<int> &p4) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1])
                == (p4[0] - p3[0]) * (p4[0] - p3[0]) + (p4[1] - p3[1]) * (p4[1] - p3[1]);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> arr = {p1, p2, p3, p4};
        sort(arr.begin(), arr.end(), [](const vector<int> &p1, const vector<int> &p2){
            if(p1[0] == p2[0]) {
                return p1[1] < p2[1];
            }
            return p1[0] < p2[0];
        });
        if(arr[0][0] == arr[1][0] && arr[0][1] == arr[1][1]) {
            return false;
        }
        return isEqual(arr[0], arr[3], arr[1], arr[2]) && isEqual(arr[0], arr[1], arr[0], arr[2]);
    }
};