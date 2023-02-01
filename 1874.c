#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _Stack
{  
    int value;
    void *next;
} Stack;

Stack* push(Stack **s, int v);
Stack* pop(Stack **s);
bool updateResult(int input, bool* res, int *index, int *pushed, Stack** s);
void my_pushing_stack(int input, bool* res, int *index, int *pushed, Stack** s);
void myPopingStack(bool* res, int *index, Stack** s);


int main()
{
    int n;
    scanf("%d", &n);
    int *input = (int*)malloc(sizeof(int)*n);
    bool *res = (bool*)malloc(sizeof(bool)*n*2);
    int pushed = 0;
    int index = 0;
    bool no = false;

    Stack** s = (Stack**)malloc(sizeof(Stack*));
    *s = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
        if(!no && !updateResult(input[i], res, &index, &pushed, s)) no = true;
    }

    if(no)
    {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < 2*n; i++)
    {
        if(res[i]){
            printf("+\n");
            continue;
        }
        printf("-\n");
    }
    
    return 0;
}

Stack* push(Stack **s, int v)
{
    Stack *node = (Stack*)malloc(sizeof(Stack));
    node->value = v;
    node->next = *s;
    *s = node;
    return node;
}

Stack* pop(Stack **s)
{
    Stack* n = (Stack*)(*s)->next;
    free(*s);
    *s = n;
    return n;
}

bool updateResult(int input, bool* res, int *index, int *pushed, Stack** s)
{
    if (input>*pushed)
    {
        my_pushing_stack(input, res, index, pushed, s);
        return true;
    }
    // input<pushed (there is no case that input==pushed)
    if((*s)->value == input)
    {
        myPopingStack(res, index, s);  
        return true;
    }
    return false;
}

void my_pushing_stack(int input, bool* res, int *index, int *pushed, Stack** s)
{
    for (int i = *pushed+1; i <= input; i++)
    {
        push(s, i);
        res[*index] = true;
        *index +=1;//*index ++; didn't work
    }
    myPopingStack(res, index, s);
    *pushed = input;
    return;
}

void myPopingStack(bool* res, int *index, Stack** s)
{
    pop(s);
    res[*index] = false;
    *index +=1;//*index ++; didn't work
    return;
}