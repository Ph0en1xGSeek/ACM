#include <stdio.h>
#include <cctype>

int main()
{
    bool isRight;
    int len, num;
    int l , r , i;
    scanf("%d%d", &len, &num);
    char q[102];
    char s[102];
    scanf("%s", (q+1));
    for(int j = 0; j < num; j++)
    {
        for(int a = 0; a <= len + 1; a++)
            s[a] = q[a];
        int arr[10] = {0};
        isRight = true;
        scanf("%d%d", &l, &r);
        i = l;
        while(i >= l && i <= r)
        {
            if(isdigit(s[i]))
            {
                arr[s[i] - '0']++;
                s[i]--;
                if(isRight)
                    i++;
                else
                    i--;
            }
            else if(s[i] == '<')
            {
                isRight = false;
                int point = i;
                do
                {
                    i--;
                }
                while(s[i] != '>' && s[i] != '<' && !isdigit(s[i]) && i >= l && i <= r);

                if(s[i] == '>' || s[i] == '<')
                    s[point] = 'K';
            }
            else if(s[i] == '>')
            {
                isRight = true;
                int point = i;
                do
                {
                    i++;
                }
                while(s[i] != '>' && s[i] != '<' && !isdigit(s[i]) && i >= l && i <= r);
                if(s[i] == '>' || s[i] == '<')
                    s[point] = 'K';
            }
            else
            {
                if(isRight)
                    i++;
                else
                    i--;
            }
        }
        printf("%d", arr[0]);
        for(int i = 1; i < 10; i++)
            printf(" %d", arr[i]);
        printf("\n");
    }
    return 0;
}
