class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int size = array.size();
        vector<string> res;
        if(size == 0) {
            return res;
        }
        vector<int> cnt(size+1, 0);
        unordered_map<int, int> mp;
        mp[0] = -1;
        int from = 0, to = 0; 
        for(int i = 1; i <= size; ++i) {
            cnt[i] = cnt[i-1];
            if(array[i-1][0] >= '0' && array[i-1][0] <= '9') {
                ++cnt[i];
            }
            if(mp.find(2 * cnt[i] - i) != mp.end()) {
                if(to - from < i - mp[2 * cnt[i] - i] - 1) {
                    from = mp[2 * cnt[i] - i] + 1;
                    to = i;
                }
            }else {
                mp[2 * cnt[i] - i] = i - 1;
            }
        }
        if(to > from) {
            res.resize(to - from);
            copy(array.begin() + from, array.begin() + to, res.begin());
        }
        return res;
    }
};


import "unicode"

func findLongestSubarray(array []string) []string {
    size := len(array)
    cnt := 0
    mp := make(map[int]int)
    mp[0] = -1
    from, to := 0, 0
    mx_len := 0
    for i := 0; i < size; i++ {
        if unicode.IsLetter(rune(array[i][0])) {
            cnt++
        }else {
            cnt--
        }
        pos, ok := mp[cnt]
        if ok {
            if i - pos > mx_len {
                mx_len = i - pos
                from = pos + 1
                to = i + 1
            }
        }else {
            mp[cnt] = i
        }
    }
    return array[from: to]
}