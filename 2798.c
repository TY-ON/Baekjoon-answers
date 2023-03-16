#include<stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int input[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                continue;
            }
            
            for (int k = 0; k < n; k++)
            {
                if (i==k||j==k)
                {
                    continue;
                }
                int sum = input[i]+input[j]+input[k];
                if(sum<=m)
                {
                    max = max>sum?max:sum;
                }
            }
        }
    }
    
    printf("%d", max);

    return 0;
}