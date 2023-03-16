#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int open = 0;
    int res = 1;
    char input = 0;
    scanf("%c", &input);
    input = 0;
    for (int i = 0; i < n; i++)
    {
        open = 0;
        res = 1;
        while(input!='\n')
        {
            scanf("%c", &input);
            if(input=='(')
            {
                open++;
            }
            if (input==')')
            {
                if (open==0)
                {
                    res = 0;
                }
                open--;
            }
        }
        input = 0;
        if (res==0||open!=0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }

    return 0;
}