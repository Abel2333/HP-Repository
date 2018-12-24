#include<stdio.h>
void fun (double x)
{
	if (x < -5)
		printf ("%.4f\n", -x + 10);
	else if (x >= -5 && x <= 5)
		printf ("%.4f\n", x/2);
	else
		printf ("%.4f\n", 2*x - 10);
	return;
}
int main (void)
{
	double x;
	scanf ("%lf", &x);
	fun(x);
	return 0;
}
