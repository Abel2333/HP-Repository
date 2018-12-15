/*Floyd-Warshall*/
#include<stdio.h>
#define INF 99999999
int main (void)
{
	int n, way;
	int e[105][105] = {{0}};
	scanf ("%d %d", &n, &way);
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <=n; y++)
			if (x!=y)
				e[x][y] = INF;
	for (int i = 1; i <= way; i++)
	{
		int x, y, len;
		scanf ("%d %d %d", &x, &y, &len);
		e[x][y] = len;
	}

	for (int index = 1; index <= n; index++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (e[i][j] > e[i][index] + e[index][j])
					e[i][j] = e[i][index] + e[index][j];
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= n; y++)
			printf ("%d ", e[x][y]);
		printf ("\n");
	}
	return 0;
}
