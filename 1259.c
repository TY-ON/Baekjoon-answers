#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool is_palindrome(char *c);
int compare_str(char *a, char*b);

int main(){
    char input[10];

    while(true){
        scanf("%s", input);
        if(compare_str(input, "0")==0) break;

        if(is_palindrome(input)){ 
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }

    return 0;
}

bool is_palindrome(char *c){
    int n = strlen(c) - 1;

    for(int i=0;i<n-i;i++){
        if(c[i]!=c[n-i]) return false;
    }
    return true;
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