class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        int mx = INT_MIN;
        int mi = INT_MAX;
        unordered_set<int> numsSet;
        int size = places.size();
        for (int i = 0; i < size; ++i) {
            if (places[i] == 0) {
                continue;
            }
            if (numsSet.find(places[i]) != numsSet.end()) {
                return false;
            }
            mx = max(mx, places[i]);
            mi = min(mi, places[i]);
            numsSet.insert(places[i]);
        }
        if (mx < mi + 5) {
            return true;
        }
        return false;
    }
};