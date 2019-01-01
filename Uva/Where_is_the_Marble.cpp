#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000;

int main (void)
{
	int n, g, x, num[maxn], kase = 0;
	while (scanf("%d%d", &n, &g) && n)
	{
		printf("CASE# %d:\n", ++kase);
		for (int i = 0; i < n; i++) 
			scanf("%d", &num[i]);
		sort(num, num + n);
		while (q--)
		{
			scanf("%d", &x);
			int p = low_bound(num, num + n) - num;
			if (num[p] == x) printf("%d found at %d\n", x, p+1);
			else printf("%d not found\n", x);
		}
	}
	return 0;
}
