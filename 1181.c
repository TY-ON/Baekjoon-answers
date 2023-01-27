#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _word
{
    char str[51];
    int length;
} word;

void getWord(word* a);
int compareStr(word o, word c);
int checkPosition(word* arr, word c, int start);
int insertWord(word* arr, word t, int ci);
void printWords(word* arr, int r);

int main()
{
    int N;
    scanf("%d", &N);
    int currentIndex = 1;
    word* words = (word*)malloc(sizeof(word) * N);
    word tempWord;

    getWord(&tempWord);
    words[0] = tempWord;
    for (int i = 1; i < N; i++)
    {
        getWord(&tempWord);
        currentIndex += insertWord(words, tempWord, currentIndex);
    }
    printWords(words, currentIndex);
}

void getWord(word* a)
{
    scanf("%s", a->str);
    a->length = strlen(a->str);
}
int compareStr(word o, word c)
{
    if (o.length > c.length)
        return 1;
    if (o.length < c.length)
        return -1;
    if (strcmp(o.str, c.str) > 0)
        return 1;
    if (strcmp(o.str, c.str) < 0)
        return -1;
    return 0;
}
int checkPosition(word* arr, word c, int start)
{
    for (int i = start; i >= 1; i--)
    {
        switch (compareStr(arr[i - 1], c))
        {
        case 1:
            continue;

        case 0:
            return -1;

        case -1:
            return start;
        }
    }
    return 0;
}
int insertWord(word* arr, word t, int ci)
{
    int position = checkPosition(arr, t, ci);
    if (position == -1)
        return 0;

    for (int i = ci; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = t;
    return 1;
}
void printWords(word* arr, int r)
{
    for (int i = 0; i < r; i++)
    {
        printf("%s\n", arr[i].str);
    }
}