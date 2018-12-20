/*violent*/
#include<stdio.h>
int main (void)
{
	int n, i, is_prim, count = 1;
	scanf ("%d", &n);
	for (int index = 2; index <= n; index++)
	{
		for (is_prim = 1, i = 2; i*i <= index; i++)
			if (index%i==0)
			{
				is_prim = 0;
				break;
			}
		if (is_prim)
			printf ("%d%c", index, count++%9==0?'\n':' ');
	}
	if (--count%9)
		printf ("\n");
	return 0;
}
