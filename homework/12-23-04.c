#include<stdio.h>
#include<math.h>
double fun (double a, double b, double c)
{
	if (a + b <= c || a + c <= b || b + c <= a)
		return 0;
	double p = (a + b + c) / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main (void)
{
	double a, b, c, area;
	scanf ("%lf %lf %lf", &a, &b, &c);
	area = fun (a, b, c);
	printf ("%.4f\n", area);
	return 0;
}
