class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> stringLen;
        vector<string> output;
        for(int i = 0; i < words.size(); i++){
            stringLen.push_back(words[i].length());
        }
        int i = 0;
        while(i < stringLen.size()){
            int startPos = i;
            int curLen = 0;
            while(i < stringLen.size() && curLen + (i - startPos) + stringLen[i] <= maxWidth){
                curLen += stringLen[i];
                i++;
            }
            string outputString = "";
            int pad, remain;
            if(i >= stringLen.size()){
                pad = 1;
                remain = 0;
            }else if(i > startPos + 1){
                pad = (maxWidth - curLen) / (i - startPos - 1);
                remain = (maxWidth - curLen) % (i - startPos - 1);
            }else{
                pad = 0;
                remain = 0;
            }
            for(int j = startPos; j < i; j++){
                outputString += words[j];
                if (j < i-1){
                    for(int k = 0; k < pad; k++){
                        outputString += " ";
                    }
                    if(j - startPos < remain){
                        outputString += " ";
                    }
                }else if(i >= stringLen.size() || i == startPos+1){
                    for(int k = 0; k < maxWidth - curLen - (i - startPos - 1); k++){
                        outputString += " ";
                    }
                }
            }
            output.push_back(outputString);
        }
        return output;
    }
};