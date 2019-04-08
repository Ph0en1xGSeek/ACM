class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = 1;
        long long num = abs((long long) numerator);
        long long den = abs((long long) denominator);
        if(numerator < 0){
            sign *= -1;
        }
        if(denominator < 0){
            sign *= -1;
        }
        if(num == 0){
            return "0";
        }
        if(den == 0){
            return "NaN";
        }
        string res = "";
        res += to_string(num / den);
        if(num % den == 0){
            if(sign == -1){
                res = "-" + res;
            }
            return res;
        }else{
            res += ".";
        }
        long long remain = num % den;
        unordered_map<long long, int> mp;
        while(remain != 0){
            if(mp.count(remain) != 0){
                break;
            }
            mp[remain] = res.length();
            remain *= 10;
            res += to_string(remain / den);
            remain %= den;
        }
        if(remain != 0){
            res.insert(mp[remain], 1, '(');
            res.insert(res.length(), 1, ')');
        }
        if(sign == -1){
            res = "-" + res;
        }
        return res;
    }
};