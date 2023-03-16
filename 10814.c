#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n = 0;
    int age[201] = {0, };

    scanf("%d", &n);
    int* input = (int*)malloc(sizeof(int)*n);
    char** name = (char**)malloc(sizeof(char*)*n);
    for (int i = 0; i < n; i++)
    {
        name[i] = (char*)malloc(sizeof(char)*105);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &input[i], name[i]);
        age[input[i]] = 1;
    }

    for (int i = 1; i <= 200; i++)
    {
        if(age[i]==1)
        {
            for (int j = 0; j < n; j++)
            {
                if(input[j]==i)
                {
                    printf("%d %s\n", input[j], name[j]);
                }
            }
        }
    }

    return 0;
}