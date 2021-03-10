#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int cre;
    char str[10];
    int num;
    double ans;
    int totCre;
    double tot;
    while(~scanf("%d", &num))
    {
        tot = 0.0;
        totCre = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d %s", &cre, str);
            if(strcmp(str, "A") == 0)
            {
                tot = tot + 4.0*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "A-") == 0)
            {
                tot = tot + 3.7*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "B+") == 0)
            {
                tot = tot + 3.3*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "B") == 0)
            {
                tot = tot + 3.0*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "B-") == 0)
            {
                tot = tot + 2.7*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "C+") == 0)
            {
                tot = tot + 2.3*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "C") == 0)
            {
                tot = tot + 2.0*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "C-") == 0)
            {
                tot = tot + 1.7*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "D") == 0)
            {
                tot = tot + 1.3*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "D-") == 0)
            {
                tot = tot + 1.0*(double)cre;
                totCre += cre;
            }
            else if(strcmp(str, "F") == 0)
            {
                totCre += cre;
            }
        }
        if(totCre == 0)
            printf("0.00\n");
        else
        {
            ans = tot / (double)totCre;
            printf("%.2lf\n", ans);
        }
    }
    return 0;
}
