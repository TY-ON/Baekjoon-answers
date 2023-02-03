#include<stdio.h>
#include<stdbool.h>

bool is_primenumber(int num, int* prime_number, int len);



int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int prime_number[78498];
    int p_index = 0;
    if(m<=2){
        m = 3;   
    }
    prime_number[p_index++] = 2;
    if(!m&1){//m%2==0 --> xor
        m++;
    }

    for (int i = 3; i < m; i+=2)
    {   
        if(is_primenumber(i, prime_number, p_index)) prime_number[p_index++] = i;
    }
    

    for (int i = m; i <= n; i+=2)
    {   
        if(is_primenumber(i, prime_number, p_index))
        {
            prime_number[p_index++] = i;
        }
    }
    
    for (int i = 0; i < p_index; i++)
    {
        printf("%d\n", prime_number[i]);
    }
    

    scanf("%d", &n);
    return 0;
}

bool is_primenumber(int num, int* prime_number, int len)
{
    bool is_prime_number = true;
    for (int i = 0; i < len; i++)
    {
        if(num%prime_number[i]==0)
        {   
            is_prime_number = false;
            break;
        }
    }
    return is_prime_number;
}