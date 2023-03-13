#include<stdio.h>

void mergeSort(int *arr, int len);

int main()
{
    int arr[1048576];

    int len = 0;
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

    for (int i = 0; i < len; i++)
    {
        if(arr[i]==-1000001) continue;
        printf("%d\n", &arr[i]);
    }

    return 0;
}

void mergeSort(int *arr, int len)
{
    int temp[1048576];

    int *arrA = arr;
    int *arrB = temp;
    int *t = NULL;

    for (int cut = 1; cut < len; cut*=2)
    {
        for (int i = 0; i < len; i += cut*2)
        {
            int a = 0, b = 0, index = 0;
            while(a<cut&&b<cut)
            {
                if(arrA[i+a]<arrA[i+cut+b])
                {
                    arrB[i+index++] = arrA[i+a];
                    continue;
                }
                arrB[i+index++] = arrA[i+cut+b];
            }
            if(a!=cut)
            {
                for (int j = index; j < cut*2; j++)
                {
                    arrB[i+index++] = arrA[i+cut+b++];
                }
            }
            if(b!=cut)
            {
                for (int j = index; j < cut*2; j++)
                {
                    arrB[i+index++] = arrA[i+a++];
                }
            }
        }
        t = arrB;
        arrB = arrA;
        arrA = t;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = arrA[i];
    }
    
    return;
}