class Solution {
private:
    int arr[26] = {};

public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size = words.size();
        int s_size = order.length();
        for (int i = 0; i < s_size; ++i) {
            arr[order[i] - 'a'] = i;
        }
        bool ans = true;
        for (int i = 0; i < size - 1; ++i) {
            if (!cmp(words[i], words[i + 1])) {
                return false;
            }
        }
        return true;
    }

    bool cmp(string &s1, string &s2) {
        int length_1 = s1.size();
        int length_2 = s2.size();
        for (int i = 0; i < length_1 && i < length_2; ++i) {
            if (arr[s1[i] - 'a'] > arr[s2[i] - 'a']) {
                return false;
            } else if (arr[s1[i] - 'a'] < arr[s2[i] - 'a']) {
                return true;
            }
        }
        return length_1 <= length_2;
    }
};