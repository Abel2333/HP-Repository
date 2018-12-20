/*Bellman-Ford*/
#include<stdio.h>
#define INF 99999999
int u[105], v[105], w[105], dis[105];
int main (void)
{
	int n, way, aims;
	scanf ("%d %d %d", &n, &way, &aims);
	for (int i = 0; i < way; i++)
		scanf ("%d %d %d", &u[i], &v[i], &w[i]);
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dis[aims] = 0;

	int check = 1;
	for (int index = 1; index < n && check; index++)
	{
		check = 0;
		for (int i = 0; i < way; i++)
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}
	}

	int flag = 1;
	for (int i = 0; i < way && flag; i++)
		if (dis[v[i]] > dis[u[i]] + w[i])
			flag = 0;
	if (flag)
	{
		for (int i = 1; i <= n; i++)
			printf ("%d%c", dis[i], i<n?' ':'\n');
	}
	else
		printf ("This figure contains a negative loop");

	return 0;
}
