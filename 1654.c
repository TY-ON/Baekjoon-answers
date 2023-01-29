#include <stdio.h>
#include <stdlib.h>
void insertionSort(int* arr);
int getMaxLength(int* arr);
int getMaxCable(int* array, int length);
int findIndex(int* array, int stdNumber);

int SIZE;

int main()
{
    int N;
    scanf("%d %d", &SIZE, &N);

    int* OYS = (int*)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        scanf("%d",OYS[i]);
    }
    insertionSort(OYS);
    
    int maxLen = getMaxLength(OYS);
    int maxCable = getMaxCable(OYS, maxLen);  
    while(maxCable != N)
    {
        maxLen--;
        maxCable = getMaxCable(OYS,maxLen);
    }
    printf("%d", maxLen);
}
void insertionSort(int* arr)
{

}
int getMaxLength(int* arr)
{
    int maxLen;
    return maxLen;
}
int getMaxCable(int* arr, int len)
{
    int maxCable, tempIndex;
    return maxCable;
}
int findIndex(int* arr, int num)
{

}