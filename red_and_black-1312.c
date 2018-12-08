#include<stdio.h>
#include<string.h>
int w, h, tot;
char map[105][105];
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y)
{
	tot++;
	map[x][y] = '#';
	for (int i = 0; i < 4; i++)
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 0 && dy >= 0 && dx < h && dy < w && map[dx][dy] == '.')
			dfs(dx, dy);
	}
	return;
}
int main (void)
{
	while (~scanf ("%d %d", &w, &h) && (w||h))
	{
		memset (map, 0, sizeof(map));
		tot = 0;
		for (int i = 0; i < h; i++)
			scanf ("%s", map[i]);
		int flag = 0;
		for (int x = 0; x < h && !flag; x++)
			for (int y = 0; y < w && !flag; y++)
				if (map[x][y] == '@')
				{
					dfs(x, y);
					printf ("%d\n", tot);
					flag = 1;
				}
	}
	return 0;
}
