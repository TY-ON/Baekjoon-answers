#include<stdio.h>
#include<stdlib.h>

int insertion(int *arr, int n, int index);
int getMaxLength(int* arr, int num);
int getMaxCable(int* arr, int num, int length);
int findIndex(int* arr, int num);

int main(){
    int k, n;

    scanf("%d %d", &k, &n);

    int *input = (int*)malloc(sizeof(int)*k);

    for(int i=0;i<k;i++)
    {
        scanf("%d", &input[i]);
        insertion(input, i+1, i);
        
    }

    int length = getMaxLength(input, k);
    int cableNum = getMaxCable(input, k, length);
    while(n>cableNum)
    {
        length--;
        cableNum = getMaxCable(input, k, length);
    }


    return 0;
}

int insertion(int *arr, int n, int index)
{
    int temp = 0, s = 0, e = index, move = 0;

    while(s!=e)
    {
        move = arr[(s+e)/2] - arr[index];//big to small
        move = arr[index] - arr[(s+e)/2];//big to small
        if (move>0)//move to right side
        {
            s = (s+e)/2 + 1;
            continue;
        }
        if (move<0)//move to left side
        {
            e = (s+e)/2;
            continue;
        }
        if(move==0) break;
    }
    move = arr[(s+e)/2] - arr[index];
    //if (move<0)//move to s
    if (move>0) s++;

    temp = arr[index];
    for(int i=index;i>s;i--)arr[i] = arr[i-1];
    arr[s] = temp;
    return 0;
}

int getMaxLength(int* arr, int num)
{
    long long res = 0;
    for(int i=0;i<num;i++){
        res += arr[i];
    }
    return res/num;
}

int getMaxCable(int* arr, int num, int length)
{

}

int findIndex(int* arr, int num)
{    
    int temp = 0, s = 0, e = num, move = 0;

    while(s!=e)
    {
        move = arr[(s+e)/2] - arr[num];
        if (move>0)//move to right side
        {
            s = (s+e)/2 + 1;
            continue;
        }
        if (move<0)//move to left side
        {
            e = (s+e)/2;
            continue;
        }
        if(move==0) break;
    }
    move = arr[(s+e)/2] - arr[num];
    if (move>0) s++;
    return s;
}