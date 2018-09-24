#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;

struct DNA
{
    int nixu;
    char xulie [110];
};

int nixushu(char* xulie, int len)
{
    int nixu = 0;
    int a = 0 ,c = 0, g = 0;//numberOf
    for(int i = len - 1; i >= 0; i--)
    {
        switch(xulie[i])
        {
            case 'A':
                a++;
                break;
            case 'C':
                c++;
                nixu += a;
                break;
            case 'G':
                g++;
                nixu += a;
                nixu += c;
                break;
            case 'T':
                nixu += a;
                nixu += c;
                nixu += g;
                break;
        }
    }
    return nixu;
}

bool cmp(DNA a, DNA b)
{
    return a.nixu < b.nixu;
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");
    int len, num;
    while(fscanf(fp, "%d%d", &len, &num) && len)
    {
        DNA* arr = new DNA [num];
        for(int i = 0; i < num; i++)
        {
            fscanf(fp, "%s", arr[i].xulie);
            arr[i].nixu = nixushu(arr[i].xulie, len);
        }
        sort(arr, arr+num, cmp);
        for(int i = 0; i < num; i++)
            fprintf(fp2, "%s\n", arr[i].xulie);
        delete [] arr;
    }
    pclose(fp);
    pclose(fp2);
    return 0;
}
