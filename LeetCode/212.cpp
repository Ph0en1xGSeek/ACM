struct TrieNode{
    string word = "";
    TrieNode *next[26];
    TrieNode(){
        for(int i = 0; i < 26; i++){
            next[i] = nullptr;
        }
    }
};

class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> res;
    
public:
    void dfs(vector<vector<char>> &board, TrieNode *cur, int x, int y){
        if(cur->word != ""){
            res.push_back(cur->word);
            cur->word = "";
        }
        char tmp = board[x][y];
        board[x][y] = '#';
        for(int i = 0; i < 4; i++){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x >= 0 && next_y >= 0 && next_x < board.size() && next_y < board[0].size()){
                if(board[next_x][next_y] != '#' && cur->next[board[next_x][next_y] - 'a'] != nullptr)
                    dfs(board, cur->next[board[next_x][next_y] - 'a'], next_x, next_y);
            }
        }
        board[x][y] = tmp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0 || words.size() == 0){
            return res;
        }
        TrieNode *root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            TrieNode *cur = root;
            for(int j = 0; j < words[i].length(); j++){
                if(cur->next[words[i][j] - 'a'] == nullptr){
                    cur->next[words[i][j] - 'a'] = new TrieNode();
                }
                cur = cur->next[words[i][j] - 'a'];
            }
            cur->word = words[i];
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(root->next[board[i][j] - 'a'] != nullptr)
                    dfs(board, root->next[board[i][j] - 'a'], i, j);
            }
        }
        return res;
    }
};