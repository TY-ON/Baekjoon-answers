#include<stdio.h>
#include<stdlib.h>

typedef struct _QUEUE_NODE
{
    int value;
    void* next;
} QUEUE_NODE;

typedef struct _QUEUE
{
    void* output;
    void* input;
} QUEUE;

void printTestCase();
void push(QUEUE* q, int value);
int pop(QUEUE* q);

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
    int input = 0;

    int important[10] = {0, };

    scanf("%d %d", &n, &index);
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        important[input] = 1;

    }

    int res = 0;
    int temp = 0;
    for(int i=9;i>0;i--)
    {
        if (!important[i])
        {
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if(index==0)
            {
                /*code*/
                index = n;
            }
            /*code*/
            index--;
        }
    }

    printf("%d\n", res);
    return;
}

void push(QUEUE* q, int value)
{
    QUEUE_NODE* node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    node->next = (QUEUE_NODE*)(q->input);
    node->value = value;
    q->input = node;
    if(q->output==NULL)
    {
        q->output = node;
    }
    return;
}

int pop(QUEUE* q)
{
    int value = ((QUEUE_NODE*)(q->output))->value;
    QUEUE_NODE* node = q->output;
    q->output = node->next;
    free(node);
    return value;
}