#include <stdio.h>
#include <stdlib.h>

int main() {

    int rows, N;
    scanf("%d %d",&rows,&N);

    char** board_rows = (char**)malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++)
    {
        board_rows[i] = (char*)malloc(sizeof(char) * N);
    }

    for (int i = 0; i < rows)
}
/*
    for (int i = 0; i < N; i++)
    {
        free(board_rows[i]);
    }
    free(board_rows);
*/