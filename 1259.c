#include <stdio.h>
#include <string.h>
int count(int digit);
void checkPalindrome(char* num);

int main()
{
    char number[6];
    while (1)
    {
        scanf("%s", number);
        if (number[0] == '0')
            break;
        checkPalindrome(number);
    }
}

int count(int digit)
{
    if (digit % 2 == 0)
        return digit / 2;
    return (digit - 1) / 2;
}
void checkPalindrome(char* num)
{
    int digit = strlen(num);
    for (int i = 0; i < count(digit); i++)
    {
        if (num[i] == num[digit - i - 1])
            continue;

        printf("no\n");
        return;
    }
    printf("yes\n");
}