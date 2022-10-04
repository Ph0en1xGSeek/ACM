class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1 = (C - A) * (D - B);
        int a2 = (G - E) * (H - F);
        int X1 = max(A, E);
        int X2 = max(X1, min(C, G));
        int Y1 = max(B, F);
        int Y2 = max(Y1, min(D, H));
        int a3 = (X2 - X1) * (Y2 - Y1);
        return a1 - a3 + a2;
    }
};