#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(){
    string input;
    cin >> input;
    bool flag = true;
    unordered_set<char> ch_set;
    for(int i = 0; i < input.size(); i++){
        if(i != 0 && input[i] == input[i-1]){
            flag = false;
            break;
        }
        ch_set.clear();
        for(int j = i+1; j < input.size(); j++){
            if(input[j] == input[i]){
                for(int k = j+1; k < input.size(); k++){
                    if(ch_set.count(input[k]) != 0){
                        flag = false;
                        break;
                    }
                }
            }
            ch_set.insert(input[j]);
        }
    }
    if(flag){
        printf("Likes\n");
    }else{
        printf("Dislikes\n");
    }
    return 0;
}
