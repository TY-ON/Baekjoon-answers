#include<stdio.h>

int main(){
    int num;

    scanf("%d", &num);

    int n = 3;
    int i = 0, jump = 0;
    int left = 0, right = 0;
    while(num>0){
        jump = get_jump(n);
        if(left%10==6){
            jump += square(10, n+1);
        }
        if(num>jump){
            num -= jump;
            left++;
            continue;
        }
        n--;
        left *= 10;
        i++;
        /*
        jump 안되면 더 작은 점프 
        n--;
        i=0;
        6, 66, 666을 확인 가능해야 할듯
        작은 점프가 안될 때까지 이후 + 남은 num
        
        000666 ~ 999666까지 -> 3,439
        1000666 ~ 1999666 -> 3439개
        6000666 ~ 6999666 -> 3439 + 10000

        00666 ~ 99666 까지 -> 271개

        600666

        */
    }

    return 0;
}

//(((9 + 10)*9 + 100)*9 + 1000)

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
    for(int i=0;i<n;i++){
        res *= a;
    }
    return res;
}

int square(int a, int n){
    int res = 1;
    for(int i=0;i<n;i++){
        res *= a;
    }
    return res;
}