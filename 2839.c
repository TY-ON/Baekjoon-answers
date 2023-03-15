#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int res = 0;
    while(n%5!=0)
    {
        n -= 3;
        res++;
    }

    if(n<0)
    {
        printf("-1");
        return 0;
    }

    res += n/5;
    printf("%d", res);

    return 0;
}