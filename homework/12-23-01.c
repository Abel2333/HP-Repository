#include<stdio.h>
int fun (int x, int y, int z)
{
	if (x <= 0 || y <= 0 || z <= 0)
		return -1;
	int a = x;
	int b = y;
	int c = 0;
	while (a % b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	int f = b;
	a = y;
	b = z;
	while (a % b)
	{
		c = a % b;
		a = b;
		b = c;
	}	
	int s = b;
	a = f;
	b = s;
	while (a % b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}
int main (void)
{
	int x, y, z;
	scanf ("%d %d %d", &x , &y, &z);
	printf ("%d\n", fun(x, y, z));
	return 0;
}
