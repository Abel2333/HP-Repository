#include<stdio.h>
double fun (double x, int y)
{
	double sum = x;
	for (int i = 1; i < y; i++)
	{
		sum += x;
		x /= 2;
	}
	return sum;
}
int main (void)
{
	double m;
	int n;
	scanf ("%lf %d", &m, &n);
	printf ("%.4f\n", fun(m, n));
	return 0;
}
