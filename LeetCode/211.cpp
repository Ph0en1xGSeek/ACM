struct TrieNode{
    bool hasWord = false;
    TrieNode * next[26];
    TrieNode(){
        for(int i = 0 ; i < 26; i++){
            next[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            if(cur->next[word[i] - 'a'] == nullptr){
                cur->next[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->next[word[i] - 'a'];
        }
        cur->hasWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode *cur = root;
        return dfs(word, cur, 0);
    }

private:
    
    bool dfs(string &word, TrieNode *cur, int pos){
        if(pos == word.length()){
            if(cur->hasWord == true)
                return true;
            else
                return false;
        }
        if(word[pos] != '.'){
            if(cur->next[word[pos] - 'a'] != nullptr){
                return dfs(word, cur->next[word[pos] - 'a'], pos+1);
            }else{
                return false;
            }
        }else{
            for(int c = 0; c < 26; c++){
                if(cur->next[c] != nullptr && dfs(word, cur->next[c], pos+1)){
                    return true;
                }
            }
            return false;
        }
    }
    
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */