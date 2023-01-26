#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int insertion(char (*c)[51], int *order, int n, int index);
int compare_str(char *a, char*b);

int main(){
    int n = 0;
    char c[20001][51];
    int len[20001];
    int order[20001];

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%s", c[i]);
        len[i] = strlen(c[i]);
        order[i] = i;

        if(insertion(c, order, i+1, i)==-1){
            if(i==0) continue;
            n--;
            i--;
        }
    }

    for(int i=0;i<n;i++){
        printf("%s\n", c[order[i]]);
    }

    return 0;
}

int insertion(char (*c)[51], int *order, int n, int index){
    int temp = 0, s = 0, e = index, move = 0;

    while(s!=e){
        move = compare_str(c[order[(s+e)/2]], c[order[index]]);
        if (move>0)//move to right side
        {
            s = (s+e)/2 + 1;
            continue;
        }
        if (move<0)//move to left side
        {
            e = (s+e)/2;
            continue;
        }
        if(move==0){
            if(s==index) return 0;
            return -1;
        }
    }
    move = compare_str(c[order[s]], c[order[index]]);
    if(move == 0){
        if(s==index){
            return 0;
        }
        return -1;
    }
    //if (move<0)//move to s
    if (move>0)//move to s+1
    {
        s++;
    }

    temp = order[index];
    for(int i=index;i>s;i--){
        order[i] = order[i-1];
    }
    order[s] = temp;
    return 0;
}

int compare_str(char *a, char*b){
    int alen = strlen(a);
    int blen = strlen(b);
    if(alen<blen) return 1;
    if(alen>blen) return -1;

    for(int i=0;i<alen;i++){
        if(a[i]<b[i]) return 1;
        if(a[i]>b[i]) return -1;
    }
    return 0;
}