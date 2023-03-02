#include<stdio.h>

void printTestCase();
int findTopNum(int* queue, int *len);
int printNum(int* queue, int len, int num, int res);
int printTop(int* queue, int* len, int top, int* res);
void copyArr(int *original, int *copy, int len);

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printTestCase();
    }
    
    return 0;
}

void printTestCase()
{
    int n, index;
    int input[100] = {0, };

    scanf("%d %d", &n, &index);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    int res = 0;
    while(index!=-1)
    {
        index = printTop(input, &n, index, &res);
    }
    printf("%d\n", res);
}

int findTopNum(int* queue, int* len)
{
    int max = 0;
    for (int i = 0; i < *len; i++)
    {
        max = max>queue[i]?max:queue[i];
    }
    return max;
}

int printNum(int* queue, int len, int num, int res)
{
    for(int i=0;i<len;i++)
    {
        if(queue[i]==num)
        {
            res++;
        }
    }
    return res;
}

int printTop(int* queue, int* len, int index, int* res)
{
    int top = findTopNum(queue, len);

    if(top==queue[index]){
        (*res) = printNum(queue, index+1, top, *res);
        return -1;
    }

    int temp[100] = {0, };
    int temp_len = 0, temp_index = 0;

    (*res) = printNum(queue, *len, top, *res);
    for (int i = (*len)-1; i >= 0; i--)
    {
        if((queue[i]==top)||(i==0))
        {
            if(i==0&&queue[i]!=top)
            {
                i--;
            }
            for(int j=i+1;(j<(*len))&&(queue[j]!=top);j++)
            {
                if(j==index)
                {
                    temp_index = temp_len;
                }
                temp[temp_len] = queue[j];
                temp_len++;
            }
            continue;
        }
    }

    (*len) = temp_len;
    copyArr(temp, queue, *len);

    return temp_index;
}

void copyArr(int *original, int *copy, int len)
{
    for(int i=0;i<len;i++)
    {
        copy[i] = original[i];
    }
}