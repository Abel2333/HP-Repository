#include<stdio.h>
int num[1005], book[105];
int map[105][105];
int head;
int tail;
int main (void)
{
	int n, way, start, end;
	scanf ("%d %d %d %d", &n, &way, &start, &end);
	for (int x, y, i = 0; i < way; i++)
	{
		scanf ("%d %d", &x, &y);
		map[x][y] = 1;
	}
	num[tail++] = start;
	book[start] = 1;
	int has_done = 0;
	int index = 0;
	while (!has_done)
	{
		int tmp = tail;
		while (head != tmp && !has_done)
		{
			for (int i = 1; i <= n; i++)
				if (map[num[head]][i] && !book[i])
				{
					book[i] = 1;
					num[tail++] = i;
					if (i == end)
						has_done = 1;
				}
			head++;
		}
		index++;
	}
	printf ("%d\n", index);
	return 0;
}
