#include<stdio.h>
#include<string.h>
struct stack{
	int index;
	int x;
	int y;
};
int top = -1;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main (void)
{
	int w, h, tot;
	char map[105][105];

	struct stack info[1000]={{0,0,0}};
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
					top++;
					info[top].x = x;
					info[top].y = y;
					flag = 1;
				}

		while (top != -1)
			{
				int has_next = 0;
				map[info[top].x][info[top].y] = '#';
				while (info[top].index < 4)
				{
					int dx = info[top].x + dir[info[top].index][0];
					int dy = info[top].y + dir[info[top].index][1];
					info[top].index++;
					if (dx >= 0 && dy >= 0 && dx < h && dy < w && map[dx][dy] == '.')
					{
						tot++;
						top++;
						info[top].x = dx;
						info[top].y = dy;
						has_next = 1;
						break;
					}
				}
				if (!has_next)
				{
					info[top].index = 0;
					top--;
				}
			}
			printf ("%d\n", tot);

	}
	return 0;
}
