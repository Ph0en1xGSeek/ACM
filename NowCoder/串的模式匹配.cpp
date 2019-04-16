class StringPattern {
public:
    void getNext(string B, vector<int>& nex){
        nex[0] = -1;
        int lenb = B.length();
        int i = 0, j = -1;
        while(i < lenb){
            if(j == -1 || B[i] == B[j]){
                i++;
                j++;
                nex[i] = j;
            }else{
                j = nex[j];
            }
        }
    }

    int kmp(string A, string B, vector<int>& nex){
        int i = 0, j = 0;
        int lena = A.length();
        int lenb = B.length();
        while(i < lena && j < lenb){
            if(j == -1 || A[i] == B[j]){
                i++;
                j++;
            }else{
                j = nex[j];
            }
        }
        if(j == lenb){
            return i - lenb;
        }else{
            return -1;
        }
    }
    int findAppearance(string A, int lena, string B, int lenb) {
        // write code here
        lena = A.length();
        lenb = B.length();
        vector<int> nex;
        for(int i = 0; i < lenb; i++){
            nex.push_back(0);
        }
        getNext(B, nex);
        int pos = kmp(A, B, nex);
        return pos;
    }
};