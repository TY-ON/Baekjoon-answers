#include <stdio.h>

int main() {
	
	int x, y, w, h, minimumDistance = 999;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	if (x < minimumDistance)
	{
		minimumDistance = x;
	}
	if (y < minimumDistance)
	{
		minimumDistance = y;
	}
	if (w - x < minimumDistance)
	{
		minimumDistance = w - x;
	}
	if (h - y < minimumDistance)
	{
		minimumDistance = h - y;
	}
	printf("%d", minimumDistance);
}