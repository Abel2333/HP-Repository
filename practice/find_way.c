#include<stdio.h>
struct queue{
	int x;
	int y;
}step[105];
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char map[105][105];
int main (void)
{
	int head = 0;
	int tail = 0;
	int w, h;
	while (scanf ("%d %d", &h, &w) && (w||h))
	{
		for (int i = 0; i < h; i++)
			scanf ("%s", map[i]);
		int flag = 1;
		for (int x = 0; x < h && flag; x++)
			for (int y = 0; y < w && flag; y++)
				if (map[x][y] == '@')
				{
					flag = 0;
					map[x][y] = '#';
					step[tail].x = x;
					step[tail].y = y;
					tail++;
				}

		int index = 0;
		int has_found = 0;
		while (!has_found)
		{
			int tmp = tail;
			while (head != tmp && !has_found)
			{
				for (int i = 0; i < 4; i++)
				{
					int dx = step[head].x + dir[i][0];
					int dy = step[head].y + dir[i][1];
					if (map[dx][dy] == '*')
					{
						has_found = 1;
						step[tail].x = dx;
						step[tail].y = dy;
						tail = (tail + 1) % 105;
						break;
					}
					if (dx < h && dy < w && dx >= 0 && dy >= 0 && map[dx][dy] == '.')
					{
						map[dx][dy] = '#';
						step[tail].x = dx;
						step[tail].y = dy;
						tail = (tail + 1) % 105;
					}
				}
				head = (head + 1) % 105;
			}
			index++;
		}
		printf ("%d\n", index);
	}
	return 0;
}
