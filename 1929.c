#include<stdio.h>
#include<stdbool.h>
#include<math.h>

/*
모든 테스트 케이스를 실행할 필요가 없다
1~ 1000000까지 소수를 모두 출력하는 테스트 케이스가 없었을 것임
--> printf로도 감당이 안되기 때문
따라서 모두 계산하는 것보다 따로 계산하는게 더 효율적이었음

+ 에라토스 테네스의 체가 더 빠르다 (%보다 *가 더 빠른듯?)

https://www.ibm.com/support/pages/which-better-divide-2-or-multiply-05
So I ran a little test to see whether there's a difference. 
Yes, indeed, there is a difference. 
A loop with a million multiplies by 0.5 took 0.11 seconds and a loop with a million divides by 2 took 1.6 seconds. 
So it's true for the RPG (and probably for the IBM i) that multiplying is quicker than dividing.
*/

bool is_primenumber(int num);

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    if(m<=2){
        printf("%d\n", 2);
        m = 3;
    }

    if(!(m&1)) m++;

    for (int i = m; i <= n; i+=2)
    {
        if(is_primenumber(i)) printf("%d\n", i);
    }

    return 0;
}

bool is_primenumber(int num)
{   
    if(num == 2) return true;
    if(!(num&1)) return false;

    int square_root = sqrt(num);

    for (int i = 3; i < square_root+1; i+=2)
    {
        if(num % i==0)
        {   
            return false;
        }
    }
    return true;
}