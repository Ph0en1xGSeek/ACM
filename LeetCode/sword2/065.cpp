class TrieNode {
private:
    vector<TrieNode *> children;
public:
    int count;
    TrieNode () : children(26), count(0) {}

    TrieNode* insert(string &word) {
        int size = word.length();
        TrieNode *cur = this;
        for (int i = size - 1; i >= 0; --i) {
            if (cur -> children[word[i] - 'a'] == nullptr) {
                cur -> children[word[i] - 'a'] = new TrieNode();
            }
            (cur -> count) ++;
            cur = cur -> children[word[i] - 'a'];

        }
        return cur;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<TrieNode *, int> leaf_map;
        TrieNode *root = new TrieNode();
        int size = words.size();
        for (int i = 0; i < size; ++i) {
            TrieNode * ret = root->insert(words[i]);
            leaf_map[ret] = i;
        }
        int ans = 0;
        for (unordered_map<TrieNode*, int>::iterator iter = leaf_map.begin(); iter != leaf_map.end(); ++iter) {
            TrieNode *node = iter -> first;
            int idx = iter -> second;
            if (node -> count == 0) {
                ans += words[idx].length() + 1;
            }

        }
        return ans;
    }
};