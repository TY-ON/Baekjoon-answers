#include<stdio.h>

int main(){
    int x, y, w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    int min = 1001;

    min = x<y?x:y;
    min = min<w-x?min:w-x;
    min = min<h-y?min:h-y;
    printf("%d", min);

    return 0;
}