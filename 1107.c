#include <stdio.h>
#include <string.h>

int findBig(char* channel, char* uselessN);
int findSmall(char* channel, char* uselessN);
int castStrToInt(char* string);
int getClosest(char* channel, int a, int b);
int getCount(char* channel, int closest);

int main() 
{
    char channel[7];
    int M;
    char uselessN[10] = {0,};

    scanf("%s",channel);
    scanf("%d",&M);
    for(int i = 0; i < M; i++)
    {
        int temp;
        scanf("%d", &temp);
        uselessN[temp] = 1;
    }
    
    int big = findBig(channel, uselessN);
    int small = findSmall(channel, uselessN);
}
int findBig(char* channel, char* uselessN)
{
    char number[7];
    int length = strlen(channel);
    int i = 0;
    for(; i < length; i++)
    {
        if(uselessN[channel[i] - '0'] == 0)
        {
            number[i] = channel[i];
            continue;
        }
        break;
    }
    for(int j = channel[i] - '0' + 1; j < 11; j++)
    {
        if(uselessN[j] == 0)
        {
            number[i] = j + '0';
            break;
        }
    }
    for(int k = 0; k < 10; k++)
    {
        if(uselessN[k] == 0)
        {

        }
    }
}
int findSmall(char* channel, char* uselessN);
int getClosest(char* channel, int a, int b);
int getCount(char* channel, int closest);