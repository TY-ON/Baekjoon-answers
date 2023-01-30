#include<stdio.h>
#include<stdlib.h>

int insertion(int *arr, int n, int index);
int getMaxLength(int* arr, int num, int goal);
int getMaxCable(int* arr, int num, int length);
int findIndex(int* arr, int num, int findNum);

int main()
{
    int k, n;

    scanf("%d %d", &k, &n);

    int *input = (int*)malloc(sizeof(int)*k);

    for(int i=0;i<k;i++)
    {
        scanf("%d", &input[i]);
        insertion(input, i, i);
    }
    
    int length = getMaxLength(input, k, n);
    int cableNum = getMaxCable(input, k, length);
    while(n>cableNum)
    {
        length--;
        cableNum = getMaxCable(input, k, length);
    }
    printf("%d", length);

    return 0;
}

int insertion(int *arr, int num, int index)
{
    int s = findIndex(arr, num, arr[index]);

    int temp = arr[index];
    for(int i=index;i>s;i--) arr[i] = arr[i-1];
    arr[s] = temp;
    return 0;
}

int getMaxLength(int* arr, int num, int goal)
{
    long long sum = 0;
    for(int i=0;i<num;i++) sum += arr[i];
    return sum/goal;
}

int getMaxCable(int* arr, int num, int length)
{   
    int n = arr[0]/length;
    if(n==0) return 0;
    int index = findIndex(arr, num, n*length);// 0 to index-1 thus the number of n == index
    if(index>=num) return n * num;
    return n * index + getMaxCable(&arr[index], num-index, length);
}

int findIndex(int* arr, int num, int findNum)
{    
    int temp = 0, s = 0, e = num, move = 0, mid = 0;

    while(s<=e)
    {   
        mid = (s+e)/2;
        move = arr[mid] - findNum;
        if (move>0)//move to right side
        {
            s = mid + 1;
            continue;
        }
        if (move<0)//move to left side
        {
            e = mid - 1;
            continue;
        }
        //if(move==0) 
        s = mid + 1;
        break;
    }
    return s;
}