class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int sz = rotateArray.size();
        if(sz == 0) {
            return 0;
        }
        if(rotateArray[0] < rotateArray[sz - 1]) {
            return rotateArray[0];
        }
        int l = 0, r = sz - 1;
        while(l <= r && rotateArray[l] >= rotateArray[r]) {
            int mid = (l + r) >> 1;
            if(rotateArray[mid] > rotateArray[r]) {
                l = mid + 1;
            }else if(rotateArray[mid] < rotateArray[l]) {
                r = mid;
            }else if(rotateArray[mid] == rotateArray[r]) {
                --r;
            }else if(rotateArray[mid] == rotateArray[l]) {
                ++l;
            }
        }
        return rotateArray[l];
    }
};