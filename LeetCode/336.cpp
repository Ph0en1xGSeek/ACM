struct TrieNode {
    int num;
    TrieNode *next[26];
    TrieNode() {
        num = -1;
        for(int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
};

class Solution {
public:
    void add(string &str, TrieNode *root, int pos) {
        TrieNode *cur = root;
        for(int i = 0; i < str.size(); ++i) {
            if(cur->next[str[i] - 'a'] == nullptr) {
                cur->next[str[i] - 'a'] = new TrieNode();
            }
            cur = cur->next[str[i] - 'a'];
        }
        cur->num = pos;
    }
    
    bool isPalindrome(string &str, int i, int j) {
        while(i < j) {
            if(str[i] != str[j]) {
                return false;
            }
            --j;
            ++i;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        if(words.size() == 0) return ans;
        TrieNode *root = new TrieNode();
        for(int i = 0; i < words.size(); ++i) {
            add(words[i], root, i);
        }
        if(root->num != -1) {
            for(int i = 0; i < words.size(); ++i) {
                if(i == root->num) {
                    continue;
                }
                if(isPalindrome(words[i], 0, words[i].size()-1)) {
                    ans.push_back({root->num, i});
                    ans.push_back({i, root->num});
                }
            }
        }
        
        for(int i = 0; i < words.size(); ++i) {
            if(words[i].size() == 0) {
                continue;
            }
            TrieNode *cur = root;
            for(int j = words[i].size()-1; j >= 0; --j) {
                cur = cur->next[words[i][j] - 'a'];
                if(cur == nullptr) {
                    break;
                }
                if(cur->num != -1 && cur->num != i && isPalindrome(words[i], 0, j-1)) {
                    ans.push_back({cur->num, i});
                }
            }
            
            if(cur != nullptr) {
                queue<TrieNode*> q;
                q.push(cur);
                while(!q.empty()) {
                    TrieNode *tmp = q.front();
                    q.pop();
                    if(tmp->num != -1 && tmp->num != i && words[tmp->num].size() != words[i].size()
                       && isPalindrome(words[tmp->num], words[i].size(), words[tmp->num].size()-1)) {
                        ans.push_back({tmp->num, i});
                    }
                    for(int j = 0; j < 26; ++j) {
                        if(tmp->next[j] != nullptr) {
                            q.push(tmp->next[j]);
                        }
                    }
                }
            }
        }
        free_node(root);
        return ans;
    }
    
    void free_node(TrieNode *node) {
        if(node == nullptr) return;
        for(int i = 0; i < 26; ++i) {
            free_node(node->next[i]);
        }
        delete node;
    }
};