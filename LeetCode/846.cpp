class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        unordered_map<int, int> mp;
        sort(hand.begin(), hand.end());
        int size = hand.size();
        for(int i = 0; i < size; ++i) {
            ++mp[hand[i]];
        }
        for(int i = 0; i < size; ++i) {
            if(mp[hand[i]] > 0) {
                for(int j = 0; j < W; ++j) {
                    if(mp[hand[i] + j] == 0) {
                        return false;
                    }
                    --mp[hand[i] + j];
                }
            }
        }
        return true;
    }
};