typedef int (*func)(int n);

int func0(int n) {
    return 0;
}

int funcn(int n) {
    static func arr[2] = {func0, funcn};
    return arr[!!n](n-1) + n;
}

class Solution {
public:
    int Sum_Solution(int n) {
        return funcn(n);
    }
};