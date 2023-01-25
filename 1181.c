#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make2dArray(char** pointer, int rows, int columns);
int compareLength(char* original, char* comparison);
int comparePriority(char* original, char* comparison);
void changeIndex(char* a, char* b);

int main() {

    int N;
    char** words = NULL;
    char* temp = NULL;

    make2dArray(words, N, 51);
    scanf("%s",words[0]);
    for (int i = 1; i < N; i++)
    {
        scanf("%s",words[i]);
        for (int j = i; j >= 1; j--)
        if(comparePriority(words[j], words[j-1]) == 0)
        {
            changeIndex(words[j], words[j-1]);
        }
        else if(comparePriority(words[j], words[j-1]) == 1)
        {
        }

    }
}

void make2dArray(char** p, int m, int n)
{
    p = (char**)malloc(sizeof(char*) * m);
    for (int i = 0; i < m; i++)
    {
        p[i] = (char*)malloc(sizeof(char) * n);
    }
}
int compareLength(char* o, char* c)
{
    if (strlen(o) > strlen(c)) return 1;
    else if (strlen(o) == strlen(c)) return 0;
    else return -1;
}
int comparePriority(char* o, char* c)
{
    switch(compareLength(o, c))
    {
        case 0:
            if(strcmp(o, c) < 0) return 0;
            else if(strcmp(o, c) == 0) return 1;
        case -1: return 0;
        default:
            return 2;
    }
}
void changeIndex(char* a, char* b)
{
    char* temp = NULL;
    temp = a;
    a = b;
    b = temp;
}