class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int size = A.size();
        for(int i = 1; i < size; ++i) {
            A[i] += A[i-1];
        }
        int sum = A[size - 1];
        if(sum % 3 != 0) {
            return false;
        }
        int pos = 0;
        int target = sum / 3;
        while(pos < size) {
            if(A[pos] == target) {
                ++pos;
                break;
            }
            ++pos;
        }
        target <<= 1;
        while(pos < size) {
            if(A[pos] == target && pos < size - 1) {
                return true;
            }
            ++pos;
        }
        return false;
    }
};