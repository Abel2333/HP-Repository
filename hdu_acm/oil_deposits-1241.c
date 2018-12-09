/*http://acm.hdu.edu.cn/showproblem.php?pid=1241*/
#include<stdio.h>
int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
char map[105][105];
int ans, m, n;
void dfs (int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx < m && dy < n && dx >= 0 && dy >=0 && map[dx][dy] == '@')
		{
			map[dx][dy] = '*';
			dfs(dx, dy);
		}
	}

	return;
}
int main (void)
{
	while (scanf ("%d %d", &m, &n) && (m||n))
	{
		ans = 0;
		for (int i = 0; i < m; i++)
			scanf ("%s", map[i]);

		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				if (map[x][y] == '@')
				{
					ans++;
					dfs(x, y);
				}
		printf ("%d\n", ans);
	}
	return 0;
}
