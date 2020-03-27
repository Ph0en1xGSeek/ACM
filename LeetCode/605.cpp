class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int pos = 0;
        int ans = 0;
        while(pos < size) {
            if(flowerbed[pos] == 0 && (pos + 1 >= size || flowerbed[pos+1] == 0)) {
                ++ans;
                pos += 2;
            }else if(flowerbed[pos] == 0){
                pos += 3;
            }else if(flowerbed[pos] == 1) {
                pos += 2;
            }
        }
        return ans >= n;
    }
};