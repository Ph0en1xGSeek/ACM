/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    map<pair<int, int>, int> cnt;
    
    int gcd(int a, int b){
        return (b == 0)? a: gcd(b, a % b);
    }
    
    int maxPoints(vector<Point>& points) {
        if(points.size() == 0){
            return 0;
        }
        int ans = 1;
        for(int j = 0; j < points.size(); j++){
            int tmp_ans = 0;
            int duplicate = 1;
            cnt.clear();
            for(int i = 0; i < points.size(); i++){
                if(i == j) continue;
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                if(x == 0 && y != 0){
                    y = 1;
                }else if(y == 0 && x != 0){
                    x = 1;
                }else if(x == 0 && y == 0){
                    duplicate++;
                    continue;
                }
                int _gcd = gcd(x, y);
                x /= _gcd;
                y /= _gcd;
                pair<int, int> p = make_pair(x, y);
                cnt[p]++;
                tmp_ans = max(cnt[p], tmp_ans);
            }
            ans = max(ans, tmp_ans+duplicate);
        }
        
        return ans;
    }
};