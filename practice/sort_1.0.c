/*sort num*/
#include<stdio.h>
int main (void)
{
	int num[1000], gro, is_first=1;
	printf ("How many groups do you want: ");
	scanf ("%d", &gro);
	for (int count = 0, n; count < gro; count++)
	{
		printf ("How many numbers you want in this group: ");
		scanf ("%d", &n);
	
		for (int i = 0; i < n; i++)
			scanf ("%d", &num[i]);
	
		for (int index = 0; index < n; index++)
			for (int i = 0; i < n-1; i++)
			{
				if (num[i] > num[i+1])
				{
					num[i] = num[i] + num[i+1];
					num[i+1] = num[i] - num[i+1];
					num[i] = num[i] - num[i+1];
				}
			}
		if (is_first)
			is_first=0;
		else
			printf ("\n");

		printf ("Case %d : After sort num is:\n", count+1);
		for (int i = 0; i < n; i++)
			printf ("%d ", num[i]);
		printf ("\n\n");
	}
	return 0;
}
