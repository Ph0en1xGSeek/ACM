class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        stream.push(ch);
        mp[ch] += 1;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char cur = '#';
        if(!stream.empty()) {
            cur = stream.front();
            while(!stream.empty() && mp[cur] != 1) {
                stream.pop();
                cur = stream.front();
            }
            if(stream.empty()) {
                cur = '#';
            }
        }
        return cur;
    }
private:
    unordered_map<int, int> mp;
    queue<char> stream;

};