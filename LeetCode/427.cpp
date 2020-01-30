/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* dfs(vector<vector<int>> &grid, int x1, int y1, int x2, int y2) {
        Node *cur = new Node(false, false, nullptr, nullptr, nullptr, nullptr);
        int sum = grid[x2][y2];
        if(x1 > 0) {
            sum -= grid[x1-1][y2];
        }
        if(y1 > 0) {
            sum -= grid[x2][y1-1];
        }
        if(x1 > 0 && y1 > 0) {
            sum += grid[x1-1][y1-1];
        }
        if((x2 - x1 + 1) * (y2 - y1 + 1) == sum) {
            cur->val = 1;
            cur->isLeaf = true;
        }else if(sum == 0) {
            cur->val = 0;
            cur->isLeaf = true;
        }else {
            cur->val = 0;
            cur->isLeaf = false;
            int new_x = x1 + (x2 - x1) / 2;
            int new_y = y1 + (y2 - y1) / 2;
            cur->topLeft = dfs(grid, x1, y1, new_x, new_y);
            cur->topRight = dfs(grid, x1, new_y+1, new_x, y2);
            cur->bottomLeft = dfs(grid, new_x+1, y1, x2, new_y);
            cur->bottomRight = dfs(grid, new_x+1, new_y+1, x2, y2);
        }
        return cur;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int N = grid.size();
        Node *root = nullptr;
        if(N == 0) {
            return root;
        }
        for(int i = 1; i < N; ++i) {
            grid[i][0] = grid[i][0] + grid[i-1][0];
            grid[0][i] = grid[0][i] + grid[0][i-1];
        }
        for(int i = 1; i < N; ++i) {
            for(int j = 1; j < N; ++j) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]; 
            }
        }
        root = dfs(grid, 0, 0, N-1, N-1);
        return root;
    }
};