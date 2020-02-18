class Solution {
public:
    
    int genKey(int state, int cur) {
        return (state << 10) + cur;
    }
    
    bool canWin(int state, int cur) {
        if(cur >= desiredTotal_) {
            return false;
        }
        int key = genKey(state, cur);
        if(state_set.find(key) != state_set.end()) {
            return state_set[key];
        }
        for(int i = 0; i < maxChoosableInteger_; ++i) {
            if(state & (1 << i)) {
                if(!canWin(state ^ (1 << i), cur + i + 1)) {
                    return state_set[key] = true;
                }
            }
        }
        return state_set[key] = false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxChoosableInteger_ = maxChoosableInteger;
        desiredTotal_ = desiredTotal;
        if(desiredTotal == 0) {
            return true;
        }
        if((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        state_set.empty();
        int state = (1 << maxChoosableInteger) - 1;
        return canWin(state, 0);
    }

private:
    unordered_map<int, bool> state_set;
    int maxChoosableInteger_;
    int desiredTotal_;
};