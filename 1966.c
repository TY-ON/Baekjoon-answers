#include<stdio.h>

void printTestCase();
int findTopNum(int* queue, int len);
int printNum(int* queue, int len, int num, int res);
int printTop(int* queue, int len, int top, int* res);
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
        index = printTop(input, n, index, &res);
    }
    printf("%d\n", res);
}

int findTopNum(int* queue, int len)
{
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        max = max>queue[i]?max:queue[i];
    }
    return max;
}

int printTop(int* queue, int len, int index, int* res)
{
    int top = findTopNum(queue, len);

    if(top==queue[index]){
        for(int i=0;i<=index;i++)
        {
            if(queue[i]==top)
            {
                (*res)++;
            }
        }
        return -1;
    }

    int temp[100] = {0, };

    int last_top = 0;
    for (int i = 0; i < len; i++)
    {
        if(top == queue[i])
        {
            last_top = i;
            queue[i] = 0;
            (*res)++;
        }
    }

    copyArr(&queue[last_top], temp, len - last_top);
    copyArr(queue, &temp[len-last_top], last_top);

    copyArr(temp, queue, len);

    index += len-last_top;
    if(index >= len)
    {
        index -= len;
    }

    return index;
}

void copyArr(int *original, int *copy, int len)
{
    for(int i=0;i<len;i++)
    {
        copy[i] = original[i];
    }
}