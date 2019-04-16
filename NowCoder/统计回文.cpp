#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

bool isPalindrome(string s){
    int len = s.length();
    for(int i = 0; i < len / 2; i++){
        if(s[i] != s[len - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    string a, b;
    cin >> a >> b;
    int a_len = a.length();
    int b_len = b.length();
    int cnt = 0;
    for(int i = 0; i <= a_len; i++){
        string tmp = a;
        a.insert(i, b);
        if(isPalindrome(a))
            cnt++;
        a = tmp;
    }
    printf("%d\n", cnt);
    return 0;
}