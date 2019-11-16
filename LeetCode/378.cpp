struct Node {
    int val;
    int x;
    int y;
    bool operator<(const Node &b) const {
        return val > b.val;
    }
    
    Node(int _val, int _x, int _y) {
        val = _val;
        x = _x;
        y = _y;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int sz = matrix.size();
        if(sz == 0) {
            return 0;
        } 
        priority_queue<Node> q;
        q.push(Node(matrix[0][0], 0, 0));
        for(int i = 0; i < k-1; ++i) {
            Node tmp = q.top();
            q.pop();
            if(tmp.x+1 < sz && tmp.y == 0) {
                q.push(Node(matrix[tmp.x+1][tmp.y], tmp.x+1, tmp.y));
            }
            if(tmp.y+1 < sz) {
                q.push(Node(matrix[tmp.x][tmp.y+1], tmp.x, tmp.y+1));
            }
        }
        Node ans = q.top();
        return ans.val;
    }
};