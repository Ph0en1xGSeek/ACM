class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> word_map;
        int size = words.size();
        for (int i = 0; i < size; ++i) {
            int pattern = 0;
            int word_size = words[i].size();
            for (int j = 0; j < word_size; ++j) {
                pattern |= 1 << (words[i][j] - 'a');
            }
            if (word_map.find(pattern) != word_map.end()) {
                if (word_size > word_map[pattern]) {
                    word_map[pattern] = word_size;
                }
            } else {
                word_map[pattern] = word_size;
            }
        }
        int ans = 0;
        for (unordered_map<int, int>::iterator iter1 = word_map.begin();
                iter1 != word_map.end(); ++iter1) {
            int pattern1 = iter1 -> first;
            for (unordered_map<int, int>::iterator iter2 = iter1; 
                    iter2 != word_map.end(); ++iter2) {
                int pattern2 = iter2 -> first;
                if ((pattern1 & pattern2) == 0) {
                    ans = max(ans, (iter1 -> second) * (iter2 -> second));
                }
            }
        }
        return ans;
    }
};