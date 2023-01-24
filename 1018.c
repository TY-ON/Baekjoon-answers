#include <stdio.h>

int main() {

	int M, N;
	scanf("%d %d", &M, &N);

	char boardInput[50][51];
	for (int i = 0; i < M; i++)
	{
		scanf("%s", boardInput[i]);
	}
    
	int boardModified[50][50] = { 0 };
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (boardInput[i][j] == 'B')
			{
				boardModified[i][j] = 0;
			}
			else
			{
				boardModified[i][j] = 1;
			}
		}
	}
    
	int row = M - 7, col = N - 7,
		black = 32, white = 0, swit = 0,
		minimum = 32, temp;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				swit = k % 2;
				for (int l = 0; l < 4; l++)
				{
					white += boardModified[i + k][j + (l * 2) + swit];
					black -= boardModified[i + k][j + (l * 2) + ((swit + 1) % 2)];
				}
			}
			temp = white + black;
			white = 0;
			black = 32;
			if (temp > 32)
			{
				temp = 64 - temp;
			}
			if (temp < minimum)
			{
				minimum = temp;
			}
		}
	}
	printf("%d", minimum);
}