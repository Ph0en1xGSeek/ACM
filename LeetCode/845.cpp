class Solution {
public:
    int longestMountain(vector<int>& A) {
        int result = 0;
        int state = 0;
        int cur = 1;
        for(int i = 1; i < A.size(); i++){
            if(state == 0){
                if(A[i] > A[i-1]){
                    state = 1;
                    cur++;
                }
            }else if(state == 1){
                if(A[i] > A[i-1]){
                    cur++;
                }else if(A[i] < A[i-1]){
                    state = 2;
                    cur++;
                }else{
                    state = 0;
                    cur = 1;
                }
            }else if(state == 2){
                if(A[i] > A[i-1]){
                    result = max(result, cur);
                    cur = 2;
                    state = 1;
                }else if(A[i] == A[i-1]){
                    result = max(result, cur);
                    cur = 1;
                    state = 0;
                }else{
                    cur++;
                }
            }
        }
        if(state == 2){
            result = max(result, cur);
        }
        return result;
    }
};