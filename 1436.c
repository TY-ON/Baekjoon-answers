#include<stdio.h>

int setup(int left, int right, int repeat);
int get_jump(int n);
int square(int a, int n);

int main(){
    int num;

    scanf("%d", &num);

    if(num==1){
        printf("666");
        return 0;
    }
    int r_size = 0, r_plus = 0, repeat = 0;
    int left = 0, right = 0;

    while(num>0){
        if(left%10==6) r_plus++;
        if(left%100==66) r_plus++;
        if(left%1000==666) r_plus++;
        repeat = square(10, r_size+r_plus);

        if(num>repeat){
            num -= repeat;
            left++;
            r_plus = 0;
            continue;
        }
        right = num-1;
        num -= repeat;
    }

    printf("%d", setup(left, right, repeat));

    return 0;
}

int setup(int left, int right, int repeat){
    if(left%1000==666) return left * repeat + right;
    if(left%100==66) return (left * 10 + 6) * repeat + right;
    if(left%10==6) return (left * 100 + 66) * repeat + right;
    return (left * 1000 + 666) * repeat + right;
}

int get_jump(int n){//19면 9666 -> 20이면 10666;
    int res = 1;
    for(int i=0;i<n;i++){
        res *= 9;
        res += square(10, i+1);
    }
    return res;
}

int square(int a, int n){
    int res = 1;
    for(int i=0;i<n;i++) res *= a;
    return res;
}