#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct words{
    string str;
    int cnt;
    bool operator<(const words & b) const{
        if(cnt != b.cnt){
            return cnt > b.cnt;
        }else{
            return str < b.str;
        }
    }
};

int main(){
    char tmp;
    string word = "";
    map<string, int> mp;
    words arr[1000];
    while(tmp = getchar()){
        if(tmp == '\n'){
            if(word.length() > 0){
                mp[word]++;
            }
            break;
        }
        tmp = tolower(tmp);
        if(tmp == '.' || tmp == ' ' || tmp == ','){
            if(word.length() > 0){
                mp[word]++;
            }
            word = "";
        }else{
            word = word + tmp;
        }
    }
    int cnt = 0;
    for(map<string, int>::iterator iter = mp.begin(); iter != mp.end(); iter++){
        arr[cnt].str = iter->first;
        arr[cnt++].cnt = iter->second;
    }
    //sort(arr, arr+cnt);
    for(int i = 0; i < cnt; i++){
        cout << arr[i].str << ':' << arr[i].cnt << endl;
    }
    return 0;
}
