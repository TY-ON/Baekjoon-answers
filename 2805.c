#include<stdio.h>
#include<stdlib.h>

int isEnoughLogLen(int height, int need_length, int* input, int len);

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int* input = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    
    int s = 0, e = 2000000000, mid = 0;
    while (s<=e)
    {
        mid = (s+e)/2;
        if (isEnoughLogLen(mid, m, input, n))
        {
            s = mid+1;
            continue;
        }
        e = mid-1;
    }

    if(isEnoughLogLen(mid+1, m, input, n))
    {
        mid++;
    }
    if(!isEnoughLogLen(mid, m, input, n))
    {
        mid--;
    }
    
    printf("%d", mid);

    return 0;
}

int isEnoughLogLen(int height, int need_length, int* input, int len)
{
    long long sum = 0;
    for (int i = 0; i < len; i++)
    {
        if(input[i] > height)
        {
            sum += input[i] - height;
        }
    }
    if(need_length<=sum)
    {
        return 1;
    }
    return 0;
}