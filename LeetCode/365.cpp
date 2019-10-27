class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0 || (x + y) >= z && z % gcd(x, y) == 0) {
            return true;
        }else {
            return false;
        }
    }
    
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
};