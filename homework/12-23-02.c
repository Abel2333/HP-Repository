#include<stdio.h>
int fun (int x, int y)
{
	char digit[105];
	int i = 1;
	digit[0] = x % 10;
	while (x)
	{
		digit[i] = (x / 10) % 10;
		x /= 10;
		i++;
	}
	int count = 0;
	for (int index = 0; index < i; index++)
		if (digit[index] == y)
			count++;
	return count;
}
int main (void)
{
	int m, n;
	scanf ("%d %d", &m, &n);
	printf ("%d\n", fun(m, n));
	return 0;
}
