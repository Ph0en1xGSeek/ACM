class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int sz = array.size();
        vector<int> tmp;
        for(auto iter = array.begin(); iter != array.end();) {
            if((*iter & 1) == 0) {
                tmp.push_back(*iter);
                iter = array.erase(iter);
            }else {
                ++iter;
            }
        }
        for(auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
            array.push_back(*iter);
        }
    }
};