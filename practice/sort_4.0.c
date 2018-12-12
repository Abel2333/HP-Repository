#include<stdio.h>
#include<stdlib.h>
int cmp (const void * a, const void * b)
{
	return *(int * )a > *(int * )b;
}
int main (void)
{
	int num[10005];
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &num[i]);
	qsort (num, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++)
		printf ("%d\n", num[i]);
	return 0;
}
