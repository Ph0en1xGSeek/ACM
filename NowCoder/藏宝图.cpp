#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    char str1[15];
    char str2[15];
    scanf("%s %s", str1, str2);
    int pos1 = 0;
    int pos2 = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    while(pos1 < len1 && pos2 < len2){
        if(str1[pos1] != str2[pos2]){
            pos1++;
        }else{
            pos1++;
            pos2++;
        }
    }
    if(pos2 == len2){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
