#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int insertionSort(int *arr, int num);
int insertion(int *arr, int num, int index);
int binarySearch(int* arr, int num, int findNum);
int findIndex(int* arr, int num, int findNum);


int main()
{
    int n, m = 0;
    scanf("%d", &n);

    int* sample = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sample[i]);
        insertion(sample, i+1, i);
    }

    scanf("%d", &m);

    int event = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &event);
        if (binarySearch(sample, n, event) != -1)
        {
            printf("1\n");
            continue;
        }
        printf("0\n");
    }
    free(sample);

    return 0;
}

int insertionSort(int *arr, int num)
{
    for(int i=0;i<num;i++)
    {
        insertion(arr, i, i);
    }
    return 0;
}

int insertion(int *arr, int num, int index)
{
    int s = findIndex(arr, index+1, arr[index]);

    int temp = arr[index];
    for(int i=index;i>s;i--) arr[i] = arr[i-1];
    arr[s] = temp;
    return 0;
}

int binarySearch(int* arr, int num, int findNum)
{
    int index = findIndex(arr, num, findNum);
    if(index>=num) return -1;
    if(findNum == arr[index]) return index;
    return -1;
}

int findIndex(int* arr, int num, int findNum)
{    
    int temp = 0, s = 0, e = num-1, mid = 0;

    while(s<=e)
    {   
        mid = (s+e)/2;
        if (arr[mid]>findNum)//move to right side
        {
            s = mid + 1;
            continue;
        }
        if (arr[mid]<findNum)//move to left side
        {
            e = mid - 1;
            continue;
        }
        //if(move==0) 
        s = mid;
        break;
    }
    return s;
}