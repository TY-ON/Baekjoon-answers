#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int insertion(char **c, int *order, int n, int index);
int compare_str(char *a, char*b);

int main(){
    int n = 0;

    scanf("%d", &n);
    char **c = (char**)malloc(sizeof(char*)*n);
    int *len = (int*)malloc(sizeof(int)*n);
    int *order = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        c[i] = (char*)malloc(sizeof(char)*51);
        scanf("%s", c[i]);

        len[i] = strlen(c[i]);
        order[i] = i;

        if(insertion(c, order, i+1, i)==-1){
            if(i==0) continue;
            free(c[i]);
            n--;
            i--;
        }
    }
    free(len);

    for(int i=0;i<n;i++){
        printf("%s\n", c[order[i]]);
    }

    return 0;
}

int insertion(char **c, int *order, int n, int index){
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

int compare_str(char *a, char*b){//former is larger, than return -1, same 0, smaller 1
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