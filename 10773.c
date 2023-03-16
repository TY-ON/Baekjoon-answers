#include<stdio.h>

int main(void)
{
    int k;
    scanf("%d", &k);

    int input[100000];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &input[i]);
    }
    
    int delete = 0, sum = 0;
    for (int i = k-1; i >= 0; i--)
    {
        if(input[i]==0)
        {
            delete++;
            continue;
        }
        if(delete>0)
        {
            delete--;
            continue;
        }
        sum += input[i];
    }
    
    printf("%d", sum);
    return 0;
}