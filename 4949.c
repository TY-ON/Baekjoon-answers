/**
 * @file 4949.c
 * @date 2023/03/02
 * @author ty05071
 * @brief answer of problems in baekjoon, number 4949
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * @param value : stacked value
 * @param next : save bottom node
*/
typedef struct _STACKNODE
{
    int next;
    char value;
} STACKNODE;

typedef struct _STACK
{
    int top;
} STACK;

char pop(STACK* stack);
char push(STACK* stack, char data);
int myAlloc();

int arr_index = 0;
STACKNODE saves[105];

/**
 * @return Program exit code
 * @param None
 * @brief checking that bracket is well used
 * @warning None
*/
int main(void)
{
    char input;

    //show when we end test case
    int end = 1;
    STACK stack = {-1};

    //get test cases before end of test cases
    while(end!=0)
    {   
        //initial setting
        end = 0;
        input = 0;
        while(pop(&stack)!=0);

        arr_index = -1;

        //repeat get until testcase end
        for(;input != '.';end++)
        {
            //get input a character
            scanf("%c", &input);
            if(end==0&&input=='\n')
            {
                end--;
            }

            //if open bracket then push, close bracket then pop
            if(input == '(')
            {
                push(&stack, '(');
                continue;
            }
            if(input == '[')
            {
                push(&stack, '[');
                continue;
            }
            if(input == ')')
            {
                //if it doesn't have pair, res = false
                if(pop(&stack)!='(')
                {
                    printf("no\n");
                    end++;
                    break;
                }
                continue;
            }
            if(input == ']')
            {
                if(pop(&stack)!='[')
                {
                    printf("no\n");
                    end++;
                    break;
                }
                continue;
            }
            // end sequence
            if(input == '.')
            {
                if(end == 0) break;
                if(stack.top!=-1)
                {
                    printf("no\n");
                    break;
                }
                printf("yes\n");
                break;
            }
        }
        while(input != '.')
        {
            scanf("%c", &input);
        }
    }

    return 0;
}


/**
        @return char : data of popped stack, if 0 then there is no stack to pop
        @param stack : costumized STACK, get address to change 
        @brief pop the top data of stack
        @warning None
*/
char pop(STACK* stack)
{
    if(stack->top == -1)
    {
        return 0;
    }
    int index = stack->top;
    stack->top = saves[stack->top].next;
    return saves[index].value;
}

/**
 * @return char : well pushed, return data, or (maybe) NULL
 * @param stack : stack will be pushed
 * @param data : push data
 * @brief stack more data
 * @warning None
*/
char push(STACK* stack, char data)
{
    int node = myAlloc();
    saves[node].value = data;
    saves[node].next = stack->top;
    stack->top = node;
    return data;
}

int myAlloc()
{
    arr_index++;
    return arr_index;
}