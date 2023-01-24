#include<stdio.h>

int two_different(char *board, int column, int min);
int different(char *board, int column, char chessboard[8][9], int min);

int main(){
    int r, c;

    char board[52][52];

    scanf("%d %d", &r, &c);

    for(int i=0;i<r;i++){
        scanf("%s", board[i]);
    }
    int min = 100;
    for(int i=0;i<=r-8;i++){
        for(int j=0;j<=c-8;j++){
            min = two_different(&board[i][j], 52, min);
        }
    }
    printf("%d\n", min);

    return 0;
}

int two_different(char *board, int column, int min){
    char start_w[8][9] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };
    char start_b[8][9] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };

    int w = different(board, column, start_w, min);
    int b = different(board, column, start_b, min);
    return w<b?w:b;
}

int different(char *board, int column, char chessboard[8][9], int min){
    int res = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i*column+j]!=chessboard[i][j]) res++;
            if(res>=min) return min;
        }
    }
    return res;
}