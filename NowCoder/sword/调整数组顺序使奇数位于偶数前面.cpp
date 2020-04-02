class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        vector<int> tmp;
        int pos = 0;
		for(int i = 0; i < size; ++i) {
			if((array[i] & 1) == 1) {
				array[pos] = array[i];
				++pos;
			}else {
				tmp.push_back(array[i]);
			}
		}
		copy(tmp.begin(), tmp.end(), array.begin() + pos);
    }
};