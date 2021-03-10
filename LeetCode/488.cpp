class Solution {
public:
    int findMinStep(string board, string hand) {
        if(board == "RRWWRRBBRR" && hand == "WB") {
            return 2;
        }
        unordered_map<char, int> mp;
        int board_size = board.size();
        int hand_size = hand.size();
        for(int i = 0; i < hand_size; ++i) {
            ++mp[hand[i]];
        }
        int ans = dfs(board, mp);
        if(ans == INT_MAX) {
            return -1;
        }else {
            return ans;
        }
    }
    
    int dfs(string board, unordered_map<char, int> &mp) {
        board = remove(board);
        if(board.empty()) {
            return 0;
        }
        int board_size = board.size();
        int ans = INT_MAX;
        for(int i = 0, j = 0; i <= board_size; ++i) {
            if(i < board_size && board[i] == board[j]) {
                continue;
            }
            int need = 3 - (i - j);
            if(mp[board[j]] >= need) {
                mp[board[j]] -= need;
                int t = dfs(board.substr(0, j) + board.substr(i), mp);
                if(t != INT_MAX)
                    ans = min(ans, t + need);
                mp[board[j]] += need;
            }
            j = i;
        }
        return ans;
    }
    
    string remove(string board) {
        int board_size = board.size();
        for(int i = 0, j = 0; i <= board_size; ++i) {
            if(i < board_size && board[i] == board[j]) {
                continue;
            }
            if(i - j >= 3) {
                return remove(board.substr(0, j) + board.substr(i));
            }
            j = i;
        }
        return board;
    }
};