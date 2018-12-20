/*Dijkstra*/
#include<stdio.h>
#define INF 99999999
int e[105][105];
int dis[105];
int main (void)
{
	int n, way, aims;
	scanf ("%d %d %d", &n, &way, &aims);
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			if (x!=y)
				e[x][y] = INF;
	for (int i = 0; i < way; i++)
	{
		int x, y, len;
		scanf ("%d %d %d", &x, &y, &len);
		e[x][y] = len;
	}
	for (int i = 1; i <= n; i++)
		dis[i] = e[aims][i];

	int book[105] = {0};
	book[aims] = 1;
	for (int index = 0; index < n; index++)
	{
		int real, min = INF;
		for (int i = 1; i <= n; i++)
			if (min > dis[i] && !book[i])
			{
				min = dis[i];
				real = i;
			}
		book[real] = 1;
		for (int i = 1; i <= n; i++)
			if (dis[i] > dis[real] + e[real][i])
				dis[i] = dis[real] + e[real][i];
	}
	
	for (int i = 1; i <= n; i++)
		printf ("%d%c", dis[i], i<n?' ':'\n');
	return 0;
}
