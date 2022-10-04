class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int size = cont.size();

        int a = cont[size - 1], b = 1;
        for (int i = size - 2; i >= 0; --i) {
            int tmp = a;
            a = cont[i] * a + b;
            b = tmp;
        }
        return {a, b};
    }
};