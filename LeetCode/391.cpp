class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(auto rect: rectangles) {
            push(mp1, rect[0], rect[1]);
            push(mp1, rect[2], rect[3]);
            push(mp2, rect[0], rect[3]);
            push(mp2, rect[2], rect[1]);
        }
        int cnt = 0;
        for(auto p1: mp1) {
            if(mp2.find(p1.first) == mp2.end()) {
                if(p1.second > 1) {
                    return false;
                }
                ++cnt;
                if(cnt > 2) {
                    return false;
                }
            }else {
                if(mp2[p1.first] != p1.second) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void push(unordered_map<int, int> &mp, int a, int b) {
        int key = a * 20000 + b;
        if(mp.find(key) != mp.end()) {
            ++mp[key];
        }else {
            mp[key] = 1;
        }
    }
};