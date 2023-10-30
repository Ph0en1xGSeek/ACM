class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;

        int size1 = word1.size();
        int size2 = word2.size();
        ans.reserve(size1 + size2);
        
        int i = 0, j = 0;
        while (i < size1 && j < size2) {
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        while (i < size1) {
            ans.push_back(word1[i++]);
        }
        while (j < size2) {
            ans.push_back(word2[j++]);
        }
        return ans;
    }
};