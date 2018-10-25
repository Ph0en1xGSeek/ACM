#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    char s[100002];
    char t[100002];
    while(~scanf("%s %s", s, t)){
        int slen = strlen(s);
        int tlen = strlen(t);
        int i = 0;
        int j = 0;
        while(i < slen && j < tlen){
            if(s[i] == t[j])
                i++;
            j++;
        }
        if(i == slen)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}