#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char dic[10005][20];
char tmp[20];

int main(){
    int dic_len = 0;
    while(~scanf("%s", dic[dic_len])){
        if(dic[dic_len][0] == '#')
            break;
        dic_len++;
    }
    while(~scanf("%s", tmp)){
    	if(tmp[0] == '#')
    		break;
    	bool flag = false;
    	for(int i = 0; i < dic_len; i++){
    		if(strcmp(tmp, dic[i]) == 0){
    			printf("%s is correct\n", tmp);
    			flag = true;
    			break;
    		}
    	}
    	if(flag == true)
    		continue;
    	printf("%s:", tmp);
    	int tmp_len = strlen(tmp);
    	for(int i = 0; i < dic_len; i++){
    		int cnt = 0;
    		if(tmp_len == strlen(dic[i])){
    			for(int j = 0; j < tmp_len; j++){
    				if(tmp[j] != dic[i][j])
    					cnt++;
    			}
    			if(cnt == 1)
    				printf(" %s", dic[i]);
    		}else if(tmp_len == strlen(dic[i]) + 1){
    			for(int j = 0, k = 0; j < strlen(dic[j]) && k < tmp_len; j++, k++){
    				if(dic[i][j] != tmp[k]){
    					j--;
    					cnt++;
    				}
    			}
				if(cnt <= 1)
					printf(" %s", dic[i]);
    		}else if(tmp_len == strlen(dic[i]) - 1){
    			for(int j = 0, k = 0; j < strlen(dic[i]) && k < tmp_len; j++, k++){
    				if(dic[i][j] != tmp[k]){
    					k--;
    					cnt++;
    				}
    			}
    			if(cnt <= 1)
    				printf(" %s", dic[i]);
    		}
    	}
    	printf("\n");
    }
    return 0;
}
