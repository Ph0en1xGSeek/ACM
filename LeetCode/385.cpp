/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int readnum(string &s, int &pos) {
        int sign = 1;
        int num = 0;
        if(s[pos] == '-') {
            sign = -1;
            ++pos;
        }
        while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9') {
            num = num * 10 + (s[pos] - '0');
            ++pos;
        }
        return sign * num;
    }
    
    
    NestedInteger dfs(string &s, int &pos) {
        NestedInteger ni;
        while(pos < s.size() && s[pos] != ']') {
            if(s[pos] == '[') {
                ++pos;
                NestedInteger tmp_ni = dfs(s, pos);
                ni.add(tmp_ni);
            }else if(s[pos] == '-' || (s[pos] >= '0' && s[pos] <= '9')) {
                int num = readnum(s, pos);
                NestedInteger num_ni = NestedInteger(num);
                ni.add(num_ni);
            }
            if(s[pos] == ',') {
                ++pos;
            }
        }
        if(s[pos] == ']') {
            ++pos;
        }
        return ni;
    }
    
    NestedInteger deserialize(string s) {
        int pos = 0;
        if(s[0] == '-' || (s[0] >= '0' && s[0] <= '9')) {
            int num = readnum(s, pos);
            return NestedInteger(num);
        }
        pos = 1;
        NestedInteger ans = dfs(s, pos);
        return ans;
    }
};