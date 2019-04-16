class Solution {
public:
    
    bool dfs(vector<vector<char>> & board, vector<vector<bool>>& Visited, string word, int x, int y, int pos){
        if(pos >= word.length()){
            return true;
        }
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()){
            return false;
        }
        if(Visited[x][y] == true || board[x][y] != word[pos]){
            return false;
        }
        Visited[x][y] = true;
        bool finded = dfs(board, Visited, word, x+1, y, pos+1) || dfs(board, Visited, word, x-1, y, pos+1) || \
            dfs(board, Visited, word, x, y+1, pos+1) || dfs(board, Visited, word, x, y-1, pos+1);
        Visited[x][y] = false;
        return finded;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> Visited;
        for(int i = 0; i < board.size(); i++){
            vector<bool> tmp;
            for(int j = 0; j < board[0].size(); j++){
                tmp.push_back(false);
            }
            Visited.push_back(tmp);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, Visited, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};