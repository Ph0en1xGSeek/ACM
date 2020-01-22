class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2 != 0) {
            int jin = num1 & num2;
            num1 ^= num2;
            num2 = jin << 1;
        }
        return num1;
    }
};