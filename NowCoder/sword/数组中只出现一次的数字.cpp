class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int sum = 0;
        for(int elem: data) {
            sum ^= elem;
        }
        int pos = 0;
        while(1) {
            if((sum & (1 << pos)) == 0) {
                ++pos;
            }
            break;
        }
        *num1 = 0;
        *num2 = 0;
        for(int elem: data) {
            if(elem & (1 << pos)) {
                *num1 ^= elem;
            }else {
                *num2 ^= elem;
            }
        }
        return;
    }
};