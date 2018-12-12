#include<stdio.h>
struct queue{
	int x[105];
	int y[105];
	int head;
	int tail;
};
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char map[105][105];
int main (void)
{
	struct queue step = {{0}, {0}, 0, 0};
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
					step.x[step.tail] = x;
					step.y[step.tail] = y;
					step.tail++;
				}

		int index = 0;
		int has_found = 0;
		while (map[step.x[step.head]][step.y[step.head]] != '*' && !has_found)
		{
			int tmp = step.tail;
			while (step.head != tmp && !has_found)
			{
				for (int i = 0; i < 4; i++)
				{
					int dx = step.x[step.head] + dir[i][0];
					int dy = step.y[step.head] + dir[i][1];
					if (map[dx][dy] == '*')
					{
						has_found = 1;
						step.x[step.tail] = dx;
						step.y[step.tail] = dy;
						step.tail = (step.tail + 1) % 105;
						break;
					}
					if (dx < h && dy < w && dx >= 0 && dy >= 0 && map[dx][dy] == '.')
					{
						map[dx][dy] = '#';
						step.x[step.tail] = dx;
						step.y[step.tail] = dy;
						step.tail = (step.tail + 1) % 105;
					}
				}
				step.head = (step.head + 1) % 105;
			}
			index++;
		}
		printf ("%d\n", index);
	}
	return 0;
}
