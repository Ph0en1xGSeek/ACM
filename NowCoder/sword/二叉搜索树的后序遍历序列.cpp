class Solution {
public:
    
    bool check(vector<int> &seq, int left, int right) {
        if(left == right) {
            return true;
        }
        int root = seq[right];
        int i = 0;
        for(; i < right; ++i) {
            if(seq[i] >= root) {
                break;
            }
        }
        if(i == right) {
            return true;
        }
        for(int j = i; i < right; ++i) {
            if(seq[i] < root) {
                return false;
            }
        }
        if(i == left) {
            return true;
        }
        bool isLeft = check(seq, left, i-1);
        bool isRight = check(seq, i, right-1);
        return (isLeft && isRight);
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        int sz = sequence.size();
        if(sz == 0) {
            return false;
        }
        return check(sequence, 0, sz-1);
    }
};