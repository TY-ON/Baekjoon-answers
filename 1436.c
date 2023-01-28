#include <stdio.h>
void countHead();
void printNumber();

int N;
int head;

int main()
{
    scanf("%d", &N);

    countHead();
    printNumber();
}
void countHead()
{
    int temp;

    while (1)
    {
        temp = N;

        if (head % 1000 == 666)
            N -= 1000;
        else if (head % 100 == 66)
            N -= 100;
        else if (head % 10 == 6)
            N -= 10;
        else
            N -= 1;

        if (N < 1)
        {
            N = temp;
            break;
        }
        head++;
    }
}
void printNumber()
{
    if (N == 1 && head%10 != 6)
        printf("%d%d", head, 666);
    else
    {
        while (1)
            if (head % 10 == 6)
                head /= 10;
            else
                break;

        if (head != 0) printf("%d", head);
        printf("%d%d", 666, N - 1);
    }
}