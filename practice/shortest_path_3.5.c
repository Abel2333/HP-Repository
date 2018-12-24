/*SPFA(Bellman-Ford with queue*/
#include<stdio.h>
#include<string.h>
#define INF 99999999
int queue[105], book[25], head, tail;
int main (void)
{
	int n, way, aims;
	int u[55], v[55], w[55];
	int first[25], next[60];
	memset(first, -1, sizeof(first));
	memset(next, -1, sizeof(next));
	scanf ("%d %d %d", &n, &way, &aims);
	for (int i = 0; i < way; i++)
	{
		scanf ("%d %d %d", &u[i], &v[i], &w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	int dis[25];
	for (int i = 0; i < n; i++)
		dis[i] = INF;
	dis[aims] = 0;

	queue[tail++] = aims;
	book[aims] = 1;
	while (head < tail)
	{
		int k = first[queue[head]];
		while (k != -1)
		{
			if (dis[v[k]] > dis[u[k]] + w[k])
			{
				dis[v[k]] = dis[u[k]] + w[k];
				if (!book[v[k]])
				{
					queue[tail++] = v[k];
					book[v[k]] = 1;
				}
			}
			k = next[k];
		}
		book[queue[head++]] = 0;
	}
	for (int i = 1; i <= n; i++)
		printf ("%d%c", dis[i], i<n?' ':'\n');
	return 0;
}
