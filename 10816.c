#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int* save= (int*)malloc(sizeof(int)*20000100);
    int* card = &save[10000010];

    int n;
    scanf("%d", &n);

    int input;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        card[input]++;
    }
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        printf("%d ", card[input]);
    }

    return 0;
}