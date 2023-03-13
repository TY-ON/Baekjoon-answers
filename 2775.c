#include<stdio.h>

int main()
{
    int t, k, n;
    scanf("%d", &t);
    
    int apartment[15][15];
    
    for(int j=1;j<=14;j++)
    {
        apartment[0][j] = j;
    }
    
    for(int i = 1;i<=14;i++)
    {
        for(int j=1;j<=14;j++)
        {
            if(j==1)
            {
                apartment[i][j] = apartment[i-1][j];
                continue;
            }
            apartment[i][j] = apartment[i-1][j] + apartment[i][j-1];
        }
    }
    
    for(int i=0;i<t;i++)
    {
        scanf("%d %d", &k, &n);
        printf("%d\n", apartment[k][n]);
    }
                                                               
    return 0;
}