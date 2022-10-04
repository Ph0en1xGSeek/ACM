class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int size = postorder.size();
        if (size == 0) {
            return true;
        }
        int root = INT_MAX;
        stack<int> st;
        for (int i = size - 1; i >= 0; --i) {
            if (postorder[i] > root) {
                return false;
            }
            while(!st.empty() && st.top() > postorder[i]) {
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
};



class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int size = postorder.size();
        if (size == 0) {
            return true;
        }
        return check(postorder, 0, size - 1);
    }

    bool check(vector<int> &seq, int left, int right) {
        if(left == right) {
            return true;
        }
        int root = seq[right];
        int i = left;
        for(; i < right; ++i) {
            if(seq[i] >= root) {
                break;
            }
        }
        for(int j = i; i < right; ++i) {
            if(seq[i] < root) {
                return false;
            }
        }
        bool isLeft = i == left || check(seq, left, i-1);
        bool isRight = i == right || check(seq, i, right-1);
        return (isLeft && isRight);
    }
};