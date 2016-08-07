#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    int ca;
    int num;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        scanf("%d %s", &num, str);
        if(next_permutation(str, str+strlen(str)))
            printf("%d %s\n", i, str);
        else
            printf("%d %s\n", i, "BIGGEST");
    }

    return 0;
}
/**全排列的算法，从尾开始的下降序列就是已经全排列好的子问题
接下来一个排列会将下降序列种仅仅比这个序列左边那个数大的数与其交换位置
右边恢复成顺序*/
