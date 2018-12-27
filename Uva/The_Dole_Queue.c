#include<stdio.h>
#define MAXN 25
int n, k, m, pep[MAXN];
int go (int start, int next, int times)
{
	int now = start, i = 0;
	while (times)
	{
		if (now = pep[(start + next*(i++) + (k>m?k:m)*(n + 1)) % (n + 1)])
			times--;
	}
	return now;
}
int main (void)
{
	while (scanf("%d %d %d", &n, &k, &m) && n)
	{
		for (int i = 1; i <= n; i++)
			pep[i] = i;
		int left = n;
		int p1 = 1, p2 = n;
		while (left)
		{
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			pep[p1] = pep[p2] = 0;
			printf ("%3d", p1);
			left--;
			if (p1 != p2)
			{
				printf (" %3d", p2);
				left--;
			}
			printf ("\n");
		}
	}
	return 0;
}
