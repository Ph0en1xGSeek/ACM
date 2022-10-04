class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while(w > 0) {
            if(area % w != 0) {
                --w;
            }else {
                break;
            }
        }
        return {area / w, w};
    }
};