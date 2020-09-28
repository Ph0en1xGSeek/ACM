class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        int posA = 0, posB = 0;
        vector<vector<int>> ans;
        while(posA < sizeA && posB < sizeB) {
            if(A[posA][0] > B[posB][1]) {
                ++posB;
            }else if(B[posB][0] > A[posA][1]) {
                ++posA;
            }else if(B[posB][0] < A[posA][0] && B[posB][1] >= A[posA][0] && B[posB][1] <= A[posA][1]) {
                ans.push_back({A[posA][0], B[posB][1]});
                ++posB;
            }else if(B[posB][0] >= A[posA][0] && B[posB][0] <= A[posA][1] &&
                    B[posB][1] >= A[posA][0] && B[posB][1] <= A[posA][1]) {
                ans.push_back(B[posB]);
                ++posB;
            }else if(B[posB][0] >= A[posA][0] && B[posB][0] <= A[posA][1] && B[posB][1] > A[posA][1]) {
                ans.push_back({B[posB][0], A[posA][1]});
                ++posA;
            }else if(B[posB][0] < A[posA][0] && B[posB][1] > A[posA][1]) {
                ans.push_back(A[posA]);
                ++posA;
            }
        }
        return ans;
    }
};