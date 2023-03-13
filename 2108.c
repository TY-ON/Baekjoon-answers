#include<stdio.h>
#include<math.h>

int main()
{
    int inputs[10000] = {0, };
    int *nums = &inputs[5000];

    int n, input;
    scanf("%d", &n);

    int min = 4010, max = -4010;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        nums[input]++;
        max = max>input?max:input;
        min = min<input?min:input;
    }

    int sum = 0, mid = 0, freq = 0;
    int count = 0, maxnum = 0;
    for (int i = -4010; i <= 4010; i++)
    {
        sum += i * nums[i];
        count += nums[i];
        if(count>n/2)
        {
            count = -600000;
            mid = i;
        }
        maxnum = maxnum>nums[i]?maxnum:nums[i];
    }

    count = 0;
    for (int i = -4010; i <= 4010; i++)
    {
        if(nums[i]==maxnum)
        {
            freq = i;
            if(count!=0)
            {
                break;
            }
            count = 1;
        }
    }
    
    printf("%ld\n", lround((double)sum/n));
    printf("%d\n", mid);
    printf("%d\n", freq);
    printf("%d\n", max-min);


    return 0;
}