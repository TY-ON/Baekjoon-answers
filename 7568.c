#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int input[50][3] = {0, }; // weight, height, mass
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &input[i][0], &input[i][1]);
        for(int j=0;j<i;j++)
        {
            if (input[i][0]>input[j][0]&&input[i][1]>input[j][1])
            {
                input[j][2] ++;
            }
            if (input[i][0]<input[j][0]&&input[i][1]<input[j][1])
            {
                input[i][2] ++;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", input[i][2]+1);
    }

    return 0;
}