class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() : children(26, nullptr), isEnd(false) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int size = word.length();
        Trie *cur = this;
        for (int i = 0; i < size; ++i) {
            if ((cur -> children)[word[i] - 'a'] == nullptr) {
                (cur -> children)[word[i] - 'a'] = new Trie;
            }
            cur = (cur -> children)[word[i] - 'a'];
        }
        cur -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int size = word.length();
        Trie *cur = this;
        for (int i = 0; i < size; ++i) {
            if ((cur -> children)[word[i] - 'a'] == nullptr) {
                return false;
            }
            cur = (cur -> children)[word[i] - 'a'];
        }
        return cur -> isEnd;
    }

    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int size = prefix.length();
        Trie *cur = this;
        for (int i = 0; i < size; ++i) {
            if ((cur -> children)[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            cur = (cur -> children)[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */