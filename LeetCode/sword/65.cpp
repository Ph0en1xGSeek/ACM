class Solution {
    public int add(int a, int b) {
        int tmp;
        while(b != 0) {
            tmp = a & b;
            a ^= b;
            b = tmp << 1;
        }
        return a;
    }
}