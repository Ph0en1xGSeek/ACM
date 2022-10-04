class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        int bull = 0;
        int cow = 0;
        for(int i = 0; i < secret.size(); ++i ) {
            if(secret[i] == guess[i]) {
                ++bull;
            }else {
                ++mp[secret[i]];
            }
        }
        for(int i = 0; i < guess.size(); ++i) {
            if(secret[i] != guess[i] && mp[guess[i]] != 0) {
                --mp[guess[i]];
                ++cow;
            }
        }
        ostringstream os;
        os << bull << 'A' << cow << 'B';
        return os.str();
    }
};