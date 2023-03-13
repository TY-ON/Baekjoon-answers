#include<stdio.h>

int main()
{
    int num[500005];

    int n;
    scanf("%d", &n);

    int is_throw = 1;
    for (int i = 0; i < n; i++)
    {
        num[i] = i+1;
    }

    int len = 0;

    while (n!=1)
    {
        len = 0;
        for (int i = 0; i < n; i++)
        {
            if(!is_throw)
            {
                num[len++] = num[i];
            }
            is_throw = !is_throw;
        }
        n = len;
    }
    
    printf("%d", num[0]);

    return 0;
}