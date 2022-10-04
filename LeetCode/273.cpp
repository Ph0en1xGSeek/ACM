class Solution {
public:
    string arr[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string ten_arr[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string hund_arr[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousand[5] = {"", "Thousand", "Million", "Billion"};
    
    string n2w_thousand(int num) {
        int one, ten, hundred;
        one = num % 10;
        num /= 10;
        ten = num % 10;
        num /= 10;
        hundred = num % 10;
        num /= 10;
        string res = "";
        bool space = false;
        if(hundred > 0) {
            res += arr[hundred] + " " + "Hundred";
            space = true;
        }
        if(ten > 0) {
            if(ten == 1) {
                if(!space) {
                    space = true;
                } else {
                    res += " ";
                }
                res += ten_arr[one];
                return res;
            }else {
                if(!space) {
                    space = true;
                } else {
                    res += " ";
                }
                res += hund_arr[ten];
            }
        }
        if(one > 0) {
            if(!space) {
                space = true;
            } else {
                res += " ";
            }
            res += arr[one];
        }
        return res;
    }
    
    string numberToWords(int num) {
        vector<string> res_arr;
        while(num > 0) {
            res_arr.push_back(n2w_thousand(num % 1000));
            num /= 1000;
        }
        string res = "";

        bool space = false;
        for(int i = res_arr.size() - 1; i >= 0; --i) {
            if(res_arr[i].size() == 0) {
                continue;
            }
            if(!space) {
                space = true;
            } else {
                res += " ";
            }
            if(i > 0)
                res += res_arr[i] + " " + thousand[i];
            else
                res += res_arr[i];
        }
        if(res.size() == 0) {
            res = "Zero";
        }
        return res;
    }
};