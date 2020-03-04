class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pos = n + m - 1;
        int posA = m - 1;
        int posB = n - 1;
        while(posA >= 0 && posB >= 0) {
            if(A[posA] > B[posB]) {
                A[pos--] = A[posA--];
            }else {
                A[pos--] = B[posB--];
            }
        }
        if(posB >= 0) {
            copy(B, B + posB + 1, A);
        }
    }
};