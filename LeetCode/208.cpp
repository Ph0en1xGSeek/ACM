struct TrieNode{
    bool hasWord = false;
    TrieNode *next[26];
    TrieNode(){
        hasWord = false;
        for(int i = 0; i < 26; i++){
            next[i] = nullptr;
        }
    }
};


class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            if(cur->next[word[i] - 'a'] == nullptr)
                cur->next[word[i] - 'a'] = new TrieNode;
            cur = cur->next[word[i] - 'a'];
        }
        if(cur == nullptr){
            cur = new TrieNode();
        }
        
        cur->hasWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        int i = 0;
        while(i < word.length() && cur != nullptr){
            cur = cur->next[word[i] - 'a'];
            i++;
        }
        if(cur != nullptr && cur->hasWord == true){
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        int i = 0;
        while(i < prefix.length() && cur != nullptr){
            cur = cur->next[prefix[i] - 'a'];
            i++;
        }
        if(cur != nullptr){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */