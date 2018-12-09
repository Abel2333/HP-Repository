/*echo num as snakes*/
#include<stdio.h>
#include<string.h>
#define MAX 25
int num[MAX][MAX];
int main (void)
{
	int n, x, y, tot;
	scanf ("%d", &n);
	tot = num[x=0][y=n-1] = 1;

	while (tot < n*n)
	{
		while (x+1<n && !num[x+1][y])
			num[++x][y] = ++tot;
		while (y-1>=0 && !num[x][y-1])
			num[x][--y] = ++tot;
		while (x-1>=0 && !num[x-1][y])
			num[--x][y] = ++tot;
		while (y+1<n && !num[x][y+1])
			num[x][++y] = ++tot;
	}

	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++)
			printf ("%3d", num[x][y]);
		putchar('\n');
	}
	return 0;
}
