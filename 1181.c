#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void my_sort(char (*c)[51], int n, int *len, int *order);
bool my_compare(char (*c)[51], int n, int *len, int *order, int i, int j);

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
    }
    order[n] = n;
    c[n][0] = '\0';

    my_sort(c, n, len, order);
    
    for(int i=0;i<n;i++){
        if(strcmp(c[order[i]], c[order[i+1]])==0) continue;
        printf("%s\n", c[order[i]]);
    }

    return 0;
}

void my_sort(char (*c)[51], int n, int *len, int *order){
    int temp = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(my_compare(c, n, len, order, i, j)){
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
}

bool my_compare(char (*c)[51], int n, int *len, int *order, int i, int j){
    //if i is larger, return true
    if(len[order[i]]>len[order[j]]) return true;
    if(len[order[i]]<len[order[j]]) return false;

    for(int l=0;l<len[order[i]];l++){
        if(c[order[i]][l]>c[order[j]][l]) return true;
        if(c[order[i]][l]<c[order[j]][l]) return false;
    }
    return false;
}