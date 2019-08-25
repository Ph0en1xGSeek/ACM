class Solution {
public:
    int hIndex(vector<int>& citations) {
        int mx = 0;
        for(int i = 0; i < citations.size(); ++i) {
            mx = max(mx, citations[i]);
        }
        int sz = min(int(citations.size()), mx);
        if(sz == 0) {
            return 0;
        }
        int *cntt = new int[sz]();
        for(int i = 0; i < citations.size(); ++i) {
            if(citations[i] >= sz) {
                ++cntt[sz-1];
            }else if(citations[i] > 0) {
                ++cntt[citations[i]-1];
            }
        }
        int rev_sum = 0;
        int i;
        for(i = sz-1; i >= 0; --i) {
            rev_sum += cntt[i];
            if(rev_sum >= i+1) {
                break;
            }
        }
        delete [] cntt;
        return i+1;
    }
};