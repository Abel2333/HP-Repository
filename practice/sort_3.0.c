#include<stdio.h>
int num[10005];
void sort (int lf, int rg)
{
	if (lf >= rg)
		return;
	int j = lf;
	int i = rg;
	int tmp = num[lf];
	
	while (i != j)
	{
		while (i != j && num[i] >= tmp)
			i--;
		while (i != j && num[j] <= tmp)
			j++;
		if (i != j)
		{
			num[i] = num[i] + num[j];
			num[j] = num[i] - num[j];
			num[i] = num[i] - num[j];
		}
	}
	num[lf] = num[i];
	num[i] = tmp;

	sort(lf, i-1);
	sort(i+1, rg);

	return;
}

int main (void)
{
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &num[i]);

	sort(0, n-1);
	
	for (int i = 0; i < n; i++)
		printf ("%d\n", num[i]);
	return 0;
}
