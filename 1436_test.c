#include <stdio.h>
void countHead();
void printNumber();
int getDigit(int num);

int N;
int head;

int main()
{
    for (int i = 1; i < 9000; i++)
    {
        //scanf("%d", &N);
        N = i;
        printf("%d\t", N);
        countHead();
        printf("%d\t%d\t",N, head);
        printNumber();
        printf("\n");
        head = 0;
    }
}
void countHead()
{
    int temp;

    while (1)
    {
        temp = N;

        if (head % 1000 == 666)     N -= 1000;
        else if (head % 100 == 66)  N -= 100;
        else if (head % 10 == 6)    N -= 10;
        else                        N -= 1;

        if (N < 1)
        {
            N = temp;   //restore N
            break;
        }
        head++;
    }
}
void printNumber()
{
    if (N == 1 && head % 10 != 6)
        if (head == 0)
            printf("666");
        else          
            printf("%d%d", head, 666);  //head + 666
    else
    {
        int zeros, sixs = 0;
        int tail = N - 1;

        while (1)
            if (head % 10 == 6)
            {
                head /= 10;
                sixs++;
            }
            else break;

        zeros = sixs - getDigit(tail);
        if (head != 0) printf("%d", head);
        printf("666");
        if (zeros == 1) printf("0");
        if (zeros == 2) printf("00");
        printf("%d", tail);
    }   //head(with out 6) + 666 + tail
}
int getDigit(int num)
{
    if (num == 0)
        return 1;   //digit of 0 == 1

    int digit = 0;

    while (num != 0)
    {
        num /= 10;
        digit++;
    }
    return digit;
}