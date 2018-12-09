#include<stdio.h>
#include<string.h>
struct stack{
	int index[10005];
	int x[10005];
	int y[10005];
	int top;
};
int w, h, tot;
char map[105][105];
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main (void)
{
	struct stack info={{0}, {0}, {0}, -1};
	while (~scanf ("%d %d", &w, &h) && (w||h))
	{
		memset (map, 0, sizeof(map));
		tot = 1;
		for (int i = 0; i < h; i++)
			scanf ("%s", map[i]);

		int flag = 0;

		for (int x = 0; x < h && !flag; x++)
			for (int y = 0; y < w && !flag; y++)
				if (map[x][y] == '@')
				{
					info.top++;
					info.x[info.top] = x;
					info.y[info.top] = y;
					flag = 1;
				}

		while (info.top != -1)
			{
				int has_next = 0;
				map[info.x[info.top]][info.y[info.top]] = '#';
				while (info.index[info.top]<4)
				{
					int dx = info.x[info.top] + dir[info.index[info.top]][0];
					int dy = info.y[info.top] + dir[info.index[info.top]][1];
					info.index[info.top]++;
					if (dx >= 0 && dy >= 0 && dx < h && dy < w && map[dx][dy] == '.')
					{
						tot++;
						info.top++;
						info.x[info.top] = dx;
						info.y[info.top] = dy;
						has_next = 1;
						break;
					}
				}
				if (!has_next)
				{
					info.index[info.top] = 0;
					info.top--;
				}
			}
			printf ("%d\n", tot);

	}
	return 0;
}
