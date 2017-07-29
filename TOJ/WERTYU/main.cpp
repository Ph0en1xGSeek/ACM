#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    char tmp;
    char arr[27] = "#VXSWDFGUHJKNBIO#EARYCQZT#";
    char arr2[11] = "9`12345678";

    while(scanf("%c", &tmp) != EOF)
    {
        if(tmp == '\n')
        {
            printf("\n");
            continue;
        }
        if(isupper(tmp) && arr[tmp-'A'] != '#')
            printf("%c", arr[tmp-'A']);
        else if(isdigit(tmp))
            printf("%c", arr2[tmp-'0']);
        else if(tmp == ' ') printf(" ");
        else if(tmp == '-') printf("0");
        else if(tmp == '=') printf("-");
        else if(tmp == '[') printf("P");
        else if(tmp == ']') printf("[");
        else if(tmp == '\\')    printf("]");
        else if(tmp == ';') printf("L");
        else if(tmp == '\'') printf(";");
        else if(tmp == ',') printf("M");
        else if(tmp == '.') printf(",");
        else if(tmp == '/')    printf(".");
    }
    return 0;
}
