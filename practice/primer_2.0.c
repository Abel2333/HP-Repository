/*sieve fo Eratosthenes*/
#include<stdio.h>
int num[100000005];
int main (void)
{
	int n, count = 0;
	scanf ("%d", &n);
	for (int prim = 2; prim*prim <= n; prim++)
		if (!num[prim])
			for (int i = prim; prim*i <= n; i++)
				num[prim*i] = 1;

	for (int i = 2; i <=n; i++)
		if (!num[i])
			printf ("%d%c", i, ++count%9==0?'\n':' ');
	if (count%9)
		printf ("\n");

	return 0;
}
