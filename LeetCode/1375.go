func numTimesAllBlue(light []int) int {
    size := len(light)
    mx := 0
    ans := 0
    for i:= 1; i <= size; i++ {
        if light[i - 1] > mx {
            mx = light[i - 1]
        }
        if mx == i {
            ans++
        }
    }
    return ans
}


class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int size = light.size();
        int mx = 0;
        int ans = 0;
        for(int i = 1; i <= size; ++i) {
            if(light[i - 1]  > mx) {
                mx = light[i - 1];
            }
            if(mx == i) {
                ++ans;
            }
        }
        return ans;
    }
};