#include<stdio.h>
#include<stdlib.h>

void mergeSort(int* arr, int len);

int main()
{
    int *arr = (int*)malloc(sizeof(int)*1048576);

    int len;
    scanf("%d", &len);

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = len; i < 1048576; i++)
    {
        arr[i] = -1000001;
    }
    
    mergeSort(arr, len);
    
    int n = 1;
    while(n<len)
    {
        n *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==-1000001) continue;
        printf("%d\n", arr[i]);
    }

    return 0;
}

void mergeSort(int* arr, int len)
{
    int *temp = (int*)malloc(sizeof(int)*1048576);

    int* arrA = arr;
    int* arrB = temp;
    int* t = NULL;

    int n = 1;
    while(n<len)
    {
        n *= 2;
    }

    for (int cut = 1; cut < n; cut *= 2)
    {
        for (int i = 0; i < n; i += cut*2)
        {
            int a = 0, b = 0, index = 0;
            while(a<cut&&b<cut)
            {
                if(arrA[i+a]<arrA[i+cut+b])
                {
                    arrB[i+index] = arrA[i+a];
                    index++;
                    a++;
                    continue;
                }
                arrB[i+index] = arrA[i+cut+b];
                index++;
                b++;
            }
            if(b!=cut)
            {
                for (int j = index; j < cut*2; j++)
                {
                    arrB[i+j] = arrA[i+cut+b];
                    b++;
                }
                continue;
            }
            if(a!=cut)
            {
                for (int j = index; j < cut*2; j++)
                {
                    arrB[i+j] = arrA[i+a];
                    a++;
                }
                continue;
            }
        }
        t = arrB;
        arrB = arrA;
        arrA = t;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arrA[i];
    }
    
    return;
}