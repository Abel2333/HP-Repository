#include<stdio.h>
int num[10005];
int main (void)
{
	int n;
	scanf ("%d", &n);
	for (int i = 0, mid = 0; i < n; i++)
		scanf ("%d", &mid), num[mid]++;
	for (int index = 0, count = 0; count < 10005 && index <= n; count++)
		if (num[count])
		{
			for (int i = 0; i < num[count]; i++)
				printf ("%d\n", count);
			index += num[count];
		}
	return 0;
}
